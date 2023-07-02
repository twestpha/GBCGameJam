#pragma bank 255
// SpriteSheet: test_light

#include "gbs_types.h"
#include "data/sprite_test_light_tileset.h"

BANKREF(sprite_test_light)

#define SPRITE_6_STATE_DEFAULT 0
#define SPRITE_6_STATE_FIRING 0
#define SPRITE_6_STATE_COVER_STANDING 0
#define SPRITE_6_STATE_COVER_CROUCHING 0
#define SPRITE_6_STATE_COVER_STANDING_FIRING 0
#define SPRITE_6_STATE_ROLLING 0
#define SPRITE_6_STATE_CROUCHING 0

const metasprite_t sprite_test_light_metasprite_0[]  = {
    { 0, 8, 0, 135 }, { 0, 8, 2, 135 }, { 0, -16, 0, 167 }, { 0, -8, 2, 167 }, { -16, 16, 0, 199 }, { 0, 8, 2, 199 }, { 0, -16, 0, 231 }, { 0, -8, 2, 231 },
    {metasprite_end}
};

const metasprite_t * const sprite_test_light_metasprites[] = {
    sprite_test_light_metasprite_0
};

const struct animation_t sprite_test_light_animations[] = {
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

const UWORD sprite_test_light_animations_lookup[] = {
    SPRITE_6_STATE_DEFAULT
};

const struct spritesheet_t sprite_test_light = {
    .n_metasprites = 1,
    .emote_origin = {
        .x = 0,
        .y = -32
    },
    .metasprites = sprite_test_light_metasprites,
    .animations = sprite_test_light_animations,
    .animations_lookup = sprite_test_light_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(sprite_test_light_tileset),
    .cgb_tileset = { NULL, NULL }
};
