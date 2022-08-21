#ifndef COMPONENT_MANAGER_H_
#define COMPONENT_MANAGER_H_

#include <memory>
#include <unordered_map>

#include "core/component_array.h"
#include "core/types.h"

class ComponentManager {
public:
  template <typename T>
  void register_component() {
    const char* type_name = typeid(T).name();

    assert(component_types_.find(type_name) == component_types_.end() &&
           "Registering component type more than once.");

    // Add this component type to the component type map
    component_types_.insert({type_name, next_component_type_});

    // Create a ComponentArray pointer and add it to the component arrays map
    component_arrays_.insert({type_name, std::make_shared<ComponentArray<T>>()});

    // Increment the value so that the next component registered will be different
    ++next_component_type_;
  }

  template <typename T>
  ComponentType get_component_type() {
    const char* type_name = typeid(T).name();

    assert(component_types_.find(type_name) != component_types_.end() &&
           "Component not registered before use.");

    // Return this component's type - used for creating signatures
    return component_types_[type_name];
  }

  template <typename T>
  void add_component(Entity entity, T component) {
    // Add a component to the array for an entity
    get_component_array<T>()->insert_data(entity, component);
  }

  template <typename T>
  void remove_component(Entity entity) {
    // Remove a component from the array for an entity
    get_component_array<T>()->remove_data(entity);
  }

  template <typename T>
  T& get_component(Entity entity) {
    // Get a reference to a component from the array for an entity
    return get_component_array<T>()->get_data(entity);
  }

  void entity_destroyed(Entity entity) {
    // Notify each component array that an entity has been destroyed
    // If it has a component for that entity, it will remove it
    for (auto const& pair : component_arrays_) {
      auto const& component = pair.second;

      component->entity_destroyed(entity);
    }
  }

private:
  std::unordered_map<const char*, ComponentType> component_types_{};
  std::unordered_map<const char*, std::shared_ptr<IComponentArray>> component_arrays_{};
  ComponentType next_component_type_{};

  template <typename T>
  std::shared_ptr<ComponentArray<T>> get_component_array() {
    const char* type_name = typeid(T).name();

    assert(component_types_.find(type_name) != component_types_.end() &&
           "Component not registed before use.");

    return std::static_pointer_cast<ComponentArray<T>>(component_arrays_[type_name]);
  }
};

#endif // COMPONENT_MANAGER_H_
