#pragma bank 255
// SpriteSheet: enemy_projectile

#include "gbs_types.h"
#include "data/sprite_enemy_projectile_tileset.h"

BANKREF(sprite_enemy_projectile)

#define SPRITE_0_STATE_DEFAULT 0
#define SPRITE_0_STATE_FIRING 0
#define SPRITE_0_STATE_COVER_STANDING 0
#define SPRITE_0_STATE_COVER_CROUCHING 0
#define SPRITE_0_STATE_COVER_STANDING_FIRING 0
#define SPRITE_0_STATE_ROLLING 0
#define SPRITE_0_STATE_CROUCHING 0

const metasprite_t sprite_enemy_projectile_metasprite_0[]  = {
    { 0, 4, 0, 5 },
    {metasprite_end}
};

const metasprite_t * const sprite_enemy_projectile_metasprites[] = {
    sprite_enemy_projectile_metasprite_0
};

const struct animation_t sprite_enemy_projectile_animations[] = {
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
    },
    {
        .start = 0,
        .end = 0
    }
};

const UWORD sprite_enemy_projectile_animations_lookup[] = {
    SPRITE_0_STATE_DEFAULT
};

const struct spritesheet_t sprite_enemy_projectile = {
    .n_metasprites = 1,
    .emote_origin = {
        .x = 0,
        .y = -16
    },
    .metasprites = sprite_enemy_projectile_metasprites,
    .animations = sprite_enemy_projectile_animations,
    .animations_lookup = sprite_enemy_projectile_animations_lookup,
    .bounds = {
        .left = 6,
        .bottom = 1,
        .right = 9,
        .top = -2
    },
    .tileset = TO_FAR_PTR_T(sprite_enemy_projectile_tileset),
    .cgb_tileset = { NULL, NULL }
};
