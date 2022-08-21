#ifndef COMPONENT_ARRAY_H_
#define COMPONENT_ARRAY_H_

#include <array>
#include <cassert>
#include <unordered_map>

#include "core/types.h"

class IComponentArray {
public:
  virtual ~IComponentArray() = default;
  virtual void entity_destroyed(Entity entity) = 0;
};

template <typename T>
class ComponentArray : public IComponentArray {
public:
  void insert_data(Entity entity, T component) {
    assert(entity_to_index_map_.find(entity) == entity_to_index_map_.end() &&
           "Component added to same enttiy more than once.");

    // Note(daniel): put new entry at end
    size_t new_index = size_;
    entity_to_index_map_[entity] = new_index;
    index_to_entity_map_[new_index] = entity;
    component_array_[new_index] = component;
    ++size_;
  }

  void remove_data(Entity entity) {
    assert(entity_to_index_map_.find(entity) != entity_to_index_map_.end() &&
           "Removing non-existent component.");

    // Note(daniel): Copy element at end into deleted elements place to maintain density
    size_t index_of_removed_entity = entity_to_index_map_[entity];
    size_t index_of_last_element = size_ - 1;
    component_array_[index_of_removed_entity] = component_array_[index_of_last_element];

    // Note(daniel): Update map to point to moved spot
    Entity entity_of_last_element = index_to_entity_map_[index_of_last_element];
    entity_to_index_map_[entity_of_last_element] = index_of_removed_entity;
    index_to_entity_map_[index_of_removed_entity] = entity_of_last_element;

    entity_to_index_map_.erase(entity);
    index_to_entity_map_.erase(index_of_last_element);

    --size_;
  }

  T& get_data(Entity entity) {
    assert(entity_to_index_map_.find(entity) != entity_to_index_map_.end() &&

           "Retrieving non-existent component");

    return component_array_[entity_to_index_map_[entity]];
  }

  void entity_destroyed(Entity entity) override {
    if (entity_to_index_map_.find(entity) != entity_to_index_map_.end()) {
      remove_data(entity);
    }
  }

private:
  std::array<T, max_entities> component_array_;
  std::unordered_map<Entity, size_t> entity_to_index_map_;
  std::unordered_map<size_t, Entity> index_to_entity_map_;
  size_t size_;
};

#endif // COMPONENT_ARRAY_H_
