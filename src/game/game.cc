#include "game/game.h"

#include <vector>

#include "components/gravity.h"
#include "components/rigid_body.h"
#include "components/transform.h"
#include "log.h"

Game::Game() { CORE_DEBUG("Game initialized"); }

Game::~Game() { CORE_DEBUG("Game destroyed"); }

void Game::init() {
  coordinator_.init();

  coordinator_.register_component<Gravity>();
  coordinator_.register_component<RigidBody>();
  coordinator_.register_component<Transforms>();

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

void Game::update() {}

void Game::render(Renderer& renderer) {
  renderer.clear();
  renderer.present();
}
