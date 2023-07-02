#pragma bank 255

// Scene: aim_background
// Actors

#include "gbs_types.h"
#include "data/sprite_player_aiming.h"
#include "data/actor_1_update.h"
#include "data/sprite_enemy_0.h"
#include "data/actor_4_update.h"
#include "data/actor_4_interact.h"
#include "data/sprite_blood_fx.h"

BANKREF(scene_2_actors)

const struct actor_t scene_2_actors[] = {
    {
        // player_aim_body,
        .pos = {
            .x = 72 * 16,
            .y = 128 * 16
        },
        .bounds = {
            .left = 3,
            .bottom = 7,
            .right = 12,
            .top = -16
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(sprite_player_aiming),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .persistent = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script_update = TO_FAR_PTR_T(actor_1_update),
        .reserve_tiles = 0
    },
    {
        // test_enemy,
        .pos = {
            .x = 72 * 16,
            .y = 96 * 16
        },
        .bounds = {
            .left = 3,
            .bottom = 3,
            .right = 12,
            .top = -20
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(sprite_enemy_0),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .persistent = FALSE,
        .collision_group = COLLISION_GROUP_1,
        .collision_enabled = TRUE,
        .script_update = TO_FAR_PTR_T(actor_4_update),
        .script = TO_FAR_PTR_T(actor_4_interact),
        .reserve_tiles = 0
    },
    {
        // blood_fx,
        .pos = {
            .x = 144 * 16,
            .y = 8 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(sprite_blood_fx),
        .move_speed = 16,
        .anim_tick = 3,
        .pinned = FALSE,
        .persistent = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .reserve_tiles = 0
    }
};
