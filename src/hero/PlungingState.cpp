/*
 * Copyright (C) 2009 Christopho, Solarus - http://www.solarus-engine.org
 * 
 * Solarus is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Solarus is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "hero/PlungingState.h"
#include "hero/FreeState.h"
#include "hero/SwimmingState.h"
#include "hero/BackToSolidGroundState.h"
#include "hero/HeroSprites.h"
#include "Game.h"
#include "Equipment.h"

/**
 * @brief Constructor.
 * @param hero the hero controlled by this state
 */
Hero::PlungingState::PlungingState(Hero *hero):
  State(hero) {

}

/**
 * @brief Destructor.
 */
Hero::PlungingState::~PlungingState() {

}

/**
 * @brief Starts this state.
 * @param previous_state the previous state
 */
void Hero::PlungingState::start(State *previous_state) {

  State::start(previous_state);

  sprites->set_animation_plunging();
  game->play_sound("splash");
}

/**
 * @brief Updates this state.
 */
void Hero::PlungingState::update() {

  State::update();

  Equipment *equipment = game->get_equipment();

  if (sprites->is_animation_finished()) {

    if (hero->get_ground() != GROUND_DEEP_WATER) {
      hero->set_state(new FreeState(hero));
    }
    else if (equipment->has_ability("swim")) {
      hero->set_state(new SwimmingState(hero));
    }
    else {
      equipment->remove_life(1);
      game->play_sound("message_end");
      hero->set_state(new BackToSolidGroundState(hero, false));
    }
  }
}

/**
 * @brief Returns whether the game over sequence can start in the current state.
 * @return true if the game over sequence can start in the current state
 */
bool Hero::PlungingState::can_start_gameover_sequence() {
  return false;
}

/**
 * @brief Returns whether the hero is touching the ground in the current state.
 * @return true if the hero is touching the ground in the current state
 */
bool Hero::PlungingState::is_touching_ground() {
  return false;
}
