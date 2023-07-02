#pragma bank 255
// SpriteSheet: aiming_reticle

#include "gbs_types.h"
#include "data/sprite_aiming_reticle_tileset.h"

BANKREF(sprite_aiming_reticle)

#define SPRITE_3_STATE_DEFAULT 0
#define SPRITE_3_STATE_FIRING 0
#define SPRITE_3_STATE_COVER_STANDING 0
#define SPRITE_3_STATE_COVER_CROUCHING 0
#define SPRITE_3_STATE_COVER_STANDING_FIRING 0
#define SPRITE_3_STATE_ROLLING 0
#define SPRITE_3_STATE_CROUCHING 0

const metasprite_t sprite_aiming_reticle_metasprite_0[]  = {
    { 0, 7, 0, 6 }, { 0, -7, 0, 38 },
    {metasprite_end}
};

const metasprite_t * const sprite_aiming_reticle_metasprites[] = {
    sprite_aiming_reticle_metasprite_0
};

const struct animation_t sprite_aiming_reticle_animations[] = {
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

const UWORD sprite_aiming_reticle_animations_lookup[] = {
    SPRITE_3_STATE_DEFAULT
};

const struct spritesheet_t sprite_aiming_reticle = {
    .n_metasprites = 1,
    .emote_origin = {
        .x = 0,
        .y = -16
    },
    .metasprites = sprite_aiming_reticle_metasprites,
    .animations = sprite_aiming_reticle_animations,
    .animations_lookup = sprite_aiming_reticle_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(sprite_aiming_reticle_tileset),
    .cgb_tileset = { NULL, NULL }
};
