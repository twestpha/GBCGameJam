#pragma bank 255

// Scene: level_0_test
// Actors

#include "gbs_types.h"
#include "data/sprite_enemy_0.h"
#include "data/actor_0_update.h"

BANKREF(scene_1_actors)

const struct actor_t scene_1_actors[] = {
    {
        // Actor 1,
        .pos = {
            .x = 224 * 16,
            .y = 24 * 16
        },
        .bounds = {
            .left = 3,
            .bottom = 3,
            .right = 12,
            .top = -20
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(sprite_enemy_0),
        .move_speed = 8,
        .anim_tick = 15,
        .pinned = FALSE,
        .persistent = TRUE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script_update = TO_FAR_PTR_T(actor_0_update),
        .reserve_tiles = 0
    }
};
