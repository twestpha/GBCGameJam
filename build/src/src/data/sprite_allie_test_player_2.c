#pragma bank 255
// SpriteSheet: allie_test_player_2

#include "gbs_types.h"
#include "data/sprite_allie_test_player_2_tileset.h"

BANKREF(sprite_allie_test_player_2)

#define SPRITE_1_STATE_DEFAULT 0
#define SPRITE_1_STATE_FIRING 0
#define SPRITE_1_STATE_COVER_STANDING 0
#define SPRITE_1_STATE_COVER_CROUCHING 0
#define SPRITE_1_STATE_COVER_STANDING_FIRING 0
#define SPRITE_1_STATE_ROLLING 0
#define SPRITE_1_STATE_CROUCHING 0

const metasprite_t sprite_allie_test_player_2_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { -16, 0, 2, 0 }, { 16, -8, 4, 0 }, { -16, 0, 6, 0 },
    {metasprite_end}
};

const metasprite_t * const sprite_allie_test_player_2_metasprites[] = {
    sprite_allie_test_player_2_metasprite_0
};

const struct animation_t sprite_allie_test_player_2_animations[] = {
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

const UWORD sprite_allie_test_player_2_animations_lookup[] = {
    SPRITE_1_STATE_DEFAULT
};

const struct spritesheet_t sprite_allie_test_player_2 = {
    .n_metasprites = 1,
    .emote_origin = {
        .x = 0,
        .y = -32
    },
    .metasprites = sprite_allie_test_player_2_metasprites,
    .animations = sprite_allie_test_player_2_animations,
    .animations_lookup = sprite_allie_test_player_2_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(sprite_allie_test_player_2_tileset),
    .cgb_tileset = { NULL, NULL }
};
