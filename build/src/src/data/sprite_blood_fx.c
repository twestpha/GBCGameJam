#pragma bank 255
// SpriteSheet: blood_fx

#include "gbs_types.h"
#include "data/sprite_blood_fx_tileset.h"

BANKREF(sprite_blood_fx)

#define SPRITE_5_STATE_DEFAULT 0
#define SPRITE_5_STATE_FIRING 0
#define SPRITE_5_STATE_COVER_STANDING 0
#define SPRITE_5_STATE_COVER_CROUCHING 0
#define SPRITE_5_STATE_COVER_STANDING_FIRING 0
#define SPRITE_5_STATE_ROLLING 0
#define SPRITE_5_STATE_CROUCHING 0

const metasprite_t sprite_blood_fx_metasprite_0[]  = {
    { -5, 8, 0, 5 }, { -1, -8, 0, 101 },
    {metasprite_end}
};

const metasprite_t sprite_blood_fx_metasprite_1[]  = {
    { -9, 4, 2, 5 }, { 4, -5, 4, 5 }, { -2, 10, 4, 101 },
    {metasprite_end}
};

const metasprite_t sprite_blood_fx_metasprite_2[]  = {
    { -4, 8, 2, 101 }, { -4, -5, 2, 101 }, { 3, -2, 2, 5 },
    {metasprite_end}
};

const metasprite_t sprite_blood_fx_metasprite_3[]  = {
    { -3, 12, 2, 101 }, { -10, -11, 2, 101 }, { 12, -5, 2, 5 },
    {metasprite_end}
};

const metasprite_t * const sprite_blood_fx_metasprites[] = {
    sprite_blood_fx_metasprite_0,
    sprite_blood_fx_metasprite_1,
    sprite_blood_fx_metasprite_2,
    sprite_blood_fx_metasprite_3
};

const struct animation_t sprite_blood_fx_animations[] = {
    {
        .start = 0,
        .end = 3
    },
    {
        .start = 0,
        .end = 3
    },
    {
        .start = 0,
        .end = 3
    },
    {
        .start = 0,
        .end = 3
    },
    {
        .start = 0,
        .end = 3
    },
    {
        .start = 0,
        .end = 3
    },
    {
        .start = 0,
        .end = 3
    },
    {
        .start = 0,
        .end = 3
    }
};

const UWORD sprite_blood_fx_animations_lookup[] = {
    SPRITE_5_STATE_DEFAULT
};

const struct spritesheet_t sprite_blood_fx = {
    .n_metasprites = 4,
    .emote_origin = {
        .x = 0,
        .y = -32
    },
    .metasprites = sprite_blood_fx_metasprites,
    .animations = sprite_blood_fx_animations,
    .animations_lookup = sprite_blood_fx_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(sprite_blood_fx_tileset),
    .cgb_tileset = { NULL, NULL }
};
