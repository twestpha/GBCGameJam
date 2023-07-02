#pragma bank 255

// Scene: test_lighting_scene
// Actors

#include "gbs_types.h"
#include "data/sprite_test_light.h"
#include "data/actor_5_update.h"

BANKREF(scene_3_actors)

const struct actor_t scene_3_actors[] = {
    {
        // Actor 1,
        .pos = {
            .x = 104 * 16,
            .y = 136 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(sprite_test_light),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .persistent = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script_update = TO_FAR_PTR_T(actor_5_update),
        .reserve_tiles = 0
    }
};
