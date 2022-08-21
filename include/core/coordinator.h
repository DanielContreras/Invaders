#ifndef COORDINATOR_H_
#define COORDINATOR_H_

#include <memory>

#include "core/component_manager.h"
#include "core/entity_manager.h"
#include "core/system_manager.h"
#include "types.h"
#include "log.h"

class Coordinator {
public:
  void init() {
    // Create pointers to each manager
    component_manager_ = std::make_unique<ComponentManager>();
    entity_manager_ = std::make_unique<EntityManager>();
    system_manager_ = std::make_unique<SystemManager>();
    CORE_DEBUG("Coordinator successfully initialized");
  }

  Entity create_entity() { 
    CORE_DEBUG("Entity created");
    return entity_manager_->create_entity(); 
  }

  void destroy_entity(Entity entity) {
    CORE_DEBUG("Entity destroyed");
    entity_manager_->destroy_entity(entity);
    component_manager_->entity_destroyed(entity);
    system_manager_->entity_destroyed(entity);
  }

  template <typename T>
  void register_component() {
    component_manager_->register_component<T>();
    CORE_DEBUG("Component Registered");
  }

  template <typename T>
  void add_component(Entity entity, T component) {
    component_manager_->add_component<T>(entity, component);

    auto signature = entity_manager_->get_signature(entity);
    signature.set(component_manager_->get_component_type<T>(), true);
    entity_manager_->set_signature(entity, signature);

    system_manager_->entity_signature_changed(entity, signature);
    CORE_DEBUG("Component added");
  }

  template <typename T>
  void remove_component(Entity entity) {
    component_manager_->remove_component<T>(entity);

    auto signature = entity_manager_->get_signature(entity);
    signature.set(component_manager_->get_component_type<T>(), false);
    entity_manager_->set_signature(entity, signature);

    system_manager_->entity_signature_changed(entity, signature);
    CORE_DEBUG("Component removed");
  }

  template <typename T>
  T& get_component(Entity entity) {
    return component_manager_->get_component<T>(entity);
  }

  template <typename T>
  ComponentType get_component_type() {
    return component_manager_->get_component_type<T>();
  }

  template <typename T>
  std::shared_ptr<T> register_system() {
    CORE_DEBUG("System registered");
    return system_manager_->register_system<T>();
  }

  template <typename T>
  void set_system_signature(Signature signature) {
    system_manager_->set_signature<T>(signature);
    CORE_DEBUG("System signature set");
  }

private:
  std::unique_ptr<ComponentManager> component_manager_;
  std::unique_ptr<EntityManager> entity_manager_;
  std::unique_ptr<SystemManager> system_manager_;
};

#endif // COORDINATOR_H_
