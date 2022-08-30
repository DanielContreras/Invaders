#include "game/game.h"

#include <vector>

#include "components/gravity.h"
#include "components/rigid_body.h"
#include "components/transform.h"
#include "components/renderable.h"
#include "core/types.h"
#include "systems/render_system.h"
#include "log.h"

Game::Game() { CORE_DEBUG("Game initialized"); }

Game::~Game() { CORE_DEBUG("Game destroyed"); }

void Game::init() {
  coordinator_.init();

  coordinator_.register_component<Gravity>();
  coordinator_.register_component<RigidBody>();
  coordinator_.register_component<Transforms>();
  coordinator_.register_component<Renderable>();

  render_system_ = coordinator_.register_system<RenderSystem>();
  {
    Signature signature;
    signature.set(coordinator_.get_component_type<Renderable>());
    signature.set(coordinator_.get_component_type<Transforms>());
    coordinator_.set_system_signature<RenderSystem>(signature);
  }
  render_system_->init();

  std::vector<Entity> entities(max_entities);

  for (auto& entity : entities) {
    entity = coordinator_.create_entity();
  }
}

void Game::handle_events(SDL_Event& event) {
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      is_running_ = false;
    }
  }
}

void Game::update(float dt) {
  render_system_->update(dt);
}
