#pragma bank 255
// SpriteSheet: player_aiming

#include "gbs_types.h"
#include "data/sprite_player_aiming_tileset.h"

BANKREF(sprite_player_aiming)

#define SPRITE_4_STATE_DEFAULT 0
#define SPRITE_4_STATE_FIRING 0
#define SPRITE_4_STATE_COVER_STANDING 0
#define SPRITE_4_STATE_COVER_CROUCHING 0
#define SPRITE_4_STATE_COVER_STANDING_FIRING 0
#define SPRITE_4_STATE_ROLLING 0
#define SPRITE_4_STATE_CROUCHING 8

const metasprite_t sprite_player_aiming_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { -16, 0, 2, 0 }, { 16, -8, 4, 0 }, { -16, 0, 6, 0 },
    {metasprite_end}
};

const metasprite_t sprite_player_aiming_metasprite_1[]  = {
    { 0, 8, 8, 0 }, { -16, 0, 10, 0 }, { 16, -8, 12, 0 },
    {metasprite_end}
};

const metasprite_t * const sprite_player_aiming_metasprites[] = {
    sprite_player_aiming_metasprite_0,
    sprite_player_aiming_metasprite_1
};

const struct animation_t sprite_player_aiming_animations[] = {
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
    },
    {
        .start = 1,
        .end = 1
    },
    {
        .start = 1,
        .end = 1
    },
    {
        .start = 1,
        .end = 1
    },
    {
        .start = 1,
        .end = 1
    },
    {
        .start = 1,
        .end = 1
    },
    {
        .start = 1,
        .end = 1
    },
    {
        .start = 1,
        .end = 1
    },
    {
        .start = 1,
        .end = 1
    }
};

const UWORD sprite_player_aiming_animations_lookup[] = {
    SPRITE_4_STATE_DEFAULT,
    SPRITE_4_STATE_FIRING,
    SPRITE_4_STATE_COVER_STANDING,
    SPRITE_4_STATE_COVER_CROUCHING,
    SPRITE_4_STATE_COVER_STANDING_FIRING,
    SPRITE_4_STATE_ROLLING,
    SPRITE_4_STATE_CROUCHING
};

const struct spritesheet_t sprite_player_aiming = {
    .n_metasprites = 2,
    .emote_origin = {
        .x = 0,
        .y = -32
    },
    .metasprites = sprite_player_aiming_metasprites,
    .animations = sprite_player_aiming_animations,
    .animations_lookup = sprite_player_aiming_animations_lookup,
    .bounds = {
        .left = 3,
        .bottom = 7,
        .right = 12,
        .top = -16
    },
    .tileset = TO_FAR_PTR_T(sprite_player_aiming_tileset),
    .cgb_tileset = { NULL, NULL }
};
