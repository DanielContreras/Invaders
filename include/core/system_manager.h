#ifndef SYSTEM_MANAGER_H_
#define SYSTEM_MANAGER_H_

#include <cassert>
#include <memory>
#include <unordered_map>

#include "core/system.h"
#include "core/types.h"

class SystemManager {
public:
  template <typename T>
  std::shared_ptr<T> register_system() {
    const char* type_name = typeid(T).name();

    assert(systems_.find(type_name) == systems_.end() && "Registering system more than once.");

    // Create a pointer to the system and return it so it can be used externally
    auto system = std::make_shared<T>();
    systems_.insert({type_name, system});
    return system;
  }

  template <typename T>
  void set_signature(Signature signature) {
    const char* type_name = typeid(T).name();

    assert(systems_.find(type_name) != systems_.end() && "System used before registered.");

    // Set the signature for this system
    signatures_.insert({type_name, signature});
  }

  void entity_destroyed(Entity entity) {
    // Erase a destroyed entity from all system lists
    // mEntities is a set so no check needed
    for (auto const& pair : systems_) {
      auto const& system = pair.second;

      system->entities_.erase(entity);
    }
  }

  void entity_signature_changed(Entity entity, Signature entity_signature) {
    // Notify each system that an entity's signature changed
    for (auto const& pair : systems_) {
      auto const& type = pair.first;
      auto const& system = pair.second;
      auto const& system_signature = signatures_[type];

      // Entity signature matches system signature - insert into set
      if ((entity_signature & system_signature) == system_signature) {
        system->entities_.insert(entity);
      }
      // Entity signature does not match system signature - erase from set
      else {
        system->entities_.erase(entity);
      }
    }
  }

private:
  // Map from system type string pointer to a signature
  std::unordered_map<const char*, Signature> signatures_{};

  // Map from system type string pointer to a system pointer
  std::unordered_map<const char*, std::shared_ptr<System>> systems_{};
};

#endif // SYSTEM_MANAGER_H_
