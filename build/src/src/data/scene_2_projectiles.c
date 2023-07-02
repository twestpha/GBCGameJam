#pragma bank 255

// Scene: aim_background
// Projectiles

#include "gbs_types.h"
#include "data/sprite_enemy_projectile.h"
#include "data/sprite_enemy_projectile.h"

BANKREF(scene_2_projectiles)

const struct projectile_def_t scene_2_projectiles[] = {
    {
        // Projectile 0,
        .sprite = TO_FAR_PTR_T(sprite_enemy_projectile),
        .move_speed = 0,
        .life_time = 3,
        .collision_group = COLLISION_GROUP_1,
        .collision_mask = COLLISION_GROUP_1,
        .bounds = {
            .left = 6,
            .bottom = 1,
            .right = 9,
            .top = -2
        },
        .anim_tick = 255,
        .animations = {
            {
                .start = 0,
                .end = 0
            },
            {
                .start = 0,
                .end = 0
            },
            {
                .start = 0,
                .end = 0
            },
            {
                .start = 0,
                .end = 0
            }
        },
        .initial_offset = 0
    },
    {
        // Projectile 1,
        .sprite = TO_FAR_PTR_T(sprite_enemy_projectile),
        .move_speed = 8,
        .life_time = 120,
        .collision_group = COLLISION_GROUP_3,
        .collision_mask = COLLISION_GROUP_PLAYER,
        .bounds = {
            .left = 6,
            .bottom = 1,
            .right = 9,
            .top = -2
        },
        .anim_tick = 255,
        .animations = {
            {
                .start = 0,
                .end = 0
            },
            {
                .start = 0,
                .end = 0
            },
            {
                .start = 0,
                .end = 0
            },
            {
                .start = 0,
                .end = 0
            }
        },
        .initial_offset = 0
    }
};
