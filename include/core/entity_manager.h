#ifndef ENTITY_MANAGER_H_
#define ENTITY_MANAGER_H_

#include <array>
#include <cassert>
#include <queue>

#include "types.h"

class EntityManager {
public:
  EntityManager() {
    for (Entity entity = 0; entity < max_entities; ++entity) {
      available_entities_.push(entity);
    }
  }

  Entity create_entity() {
    assert(living_entity_count < max_entities && "Too many entities in existence");

    Entity id = available_entities_.front();
    available_entities_.pop();
    ++living_entity_count;

    return id;
  }

  void destroy_entity(Entity entity) {
    assert(entity < max_entities && "Entity out of range");

    signatures_[entity].reset();
    available_entities_.push(entity);
    --living_entity_count;
  }

  void set_signature(Entity entity, Signature signature) {
    assert(entity < max_entities && "Entity out of range");

    signatures_[entity] = signature;
  }

  Signature get_signature(Entity entity) {
    assert(entity < max_entities && "Entity out of range");

    return signatures_[entity];
  }

private:
  std::queue<Entity> available_entities_{};
  std::array<Signature, max_entities> signatures_{};
  uint32_t living_entity_count{};
};

#endif // ENTITY_MANAGER_H_
