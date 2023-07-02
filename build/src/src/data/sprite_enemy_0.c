#pragma bank 255
// SpriteSheet: enemy_0

#include "gbs_types.h"
#include "data/sprite_enemy_0_tileset.h"

BANKREF(sprite_enemy_0)

#define SPRITE_2_STATE_DEFAULT 0
#define SPRITE_2_STATE_FIRING 8
#define SPRITE_2_STATE_COVER_STANDING 16
#define SPRITE_2_STATE_COVER_CROUCHING 24
#define SPRITE_2_STATE_COVER_STANDING_FIRING 32
#define SPRITE_2_STATE_ROLLING 40
#define SPRITE_2_STATE_CROUCHING 0

const metasprite_t sprite_enemy_0_metasprite_0[]  = {
    { 0, 8, 0, 2 }, { -16, 0, 2, 2 }, { 16, -8, 4, 2 }, { -16, 0, 6, 2 },
    {metasprite_end}
};

const metasprite_t sprite_enemy_0_metasprite_1[]  = {
    { -15, 8, 2, 2 }, { 0, -8, 6, 2 }, { 15, 9, 0, 2 }, { 0, -8, 4, 2 },
    {metasprite_end}
};

const metasprite_t sprite_enemy_0_metasprite_2[]  = {
    { 0, 0, 0, 34 }, { -16, 8, 2, 2 }, { 16, 0, 4, 34 }, { -16, -8, 6, 2 },
    {metasprite_end}
};

const metasprite_t sprite_enemy_0_metasprite_3[]  = {
    { -15, 8, 2, 2 }, { 0, -8, 6, 2 }, { 15, -1, 0, 34 }, { 0, 8, 4, 34 },
    {metasprite_end}
};

const metasprite_t sprite_enemy_0_metasprite_4[]  = {
    { -16, 8, 8, 2 }, { 0, -8, 10, 2 }, { 16, 8, 0, 2 }, { 0, -8, 4, 2 },
    {metasprite_end}
};

const metasprite_t sprite_enemy_0_metasprite_5[]  = {
    { -17, 6, 12, 7 }, { 0, -8, 12, 103 }, { 1, 10, 8, 7 }, { 0, -2, 10, 7 }, { 16, 2, 0, 7 }, { 0, -8, 4, 7 },
    {metasprite_end}
};

const metasprite_t sprite_enemy_0_metasprite_6[]  = {
    { -8, 8, 2, 2 }, { 0, -8, 6, 2 },
    {metasprite_end}
};

const metasprite_t sprite_enemy_0_metasprite_7[]  = {
    { -3, 8, 2, 2 }, { 0, -8, 6, 2 },
    {metasprite_end}
};

const metasprite_t sprite_enemy_0_metasprite_8[]  = {
    { -8, 8, 8, 2 }, { 0, -8, 10, 2 },
    {metasprite_end}
};

const metasprite_t sprite_enemy_0_metasprite_9[]  = {
    { -8, 5, 12, 7 }, { 0, -8, 12, 103 }, { 0, 11, 8, 7 }, { 0, -8, 10, 7 },
    {metasprite_end}
};

const metasprite_t sprite_enemy_0_metasprite_10[]  = {
    { -14, 11, 2, 2 }, { 0, -8, 6, 2 }, { 14, 4, 0, 2 }, { 0, -8, 4, 2 },
    {metasprite_end}
};

const metasprite_t sprite_enemy_0_metasprite_11[]  = {
    { 0, 8, 14, 2 }, { 0, -8, 16, 2 }, { 0, 0, 12, 98 },
    {metasprite_end}
};

const metasprite_t sprite_enemy_0_metasprite_12[]  = {
    { 0, 0, 14, 98 }, { 0, 8, 16, 98 }, { 0, 0, 12, 2 },
    {metasprite_end}
};

const metasprite_t sprite_enemy_0_metasprite_13[]  = {
    { -10, 6, 2, 2 }, { 0, -8, 6, 2 }, { 10, 11, 0, 2 }, { 0, -8, 4, 2 },
    {metasprite_end}
};

const metasprite_t sprite_enemy_0_metasprite_14[]  = {
    { -16, 8, 2, 2 }, { 0, -8, 6, 2 }, { 16, 8, 0, 2 }, { 0, -8, 4, 2 },
    {metasprite_end}
};

const metasprite_t * const sprite_enemy_0_metasprites[] = {
    sprite_enemy_0_metasprite_0,
    sprite_enemy_0_metasprite_1,
    sprite_enemy_0_metasprite_2,
    sprite_enemy_0_metasprite_3,
    sprite_enemy_0_metasprite_4,
    sprite_enemy_0_metasprite_4,
    sprite_enemy_0_metasprite_5,
    sprite_enemy_0_metasprite_4,
    sprite_enemy_0_metasprite_6,
    sprite_enemy_0_metasprite_7,
    sprite_enemy_0_metasprite_8,
    sprite_enemy_0_metasprite_8,
    sprite_enemy_0_metasprite_9,
    sprite_enemy_0_metasprite_8,
    sprite_enemy_0_metasprite_10,
    sprite_enemy_0_metasprite_11,
    sprite_enemy_0_metasprite_12,
    sprite_enemy_0_metasprite_13,
    sprite_enemy_0_metasprite_14
};

const struct animation_t sprite_enemy_0_animations[] = {
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
    },
    {
        .start = 4,
        .end = 7
    },
    {
        .start = 4,
        .end = 7
    },
    {
        .start = 4,
        .end = 7
    },
    {
        .start = 4,
        .end = 7
    },
    {
        .start = 4,
        .end = 7
    },
    {
        .start = 4,
        .end = 7
    },
    {
        .start = 4,
        .end = 7
    },
    {
        .start = 4,
        .end = 7
    },
    {
        .start = 8,
        .end = 8
    },
    {
        .start = 8,
        .end = 8
    },
    {
        .start = 8,
        .end = 8
    },
    {
        .start = 8,
        .end = 8
    },
    {
        .start = 8,
        .end = 8
    },
    {
        .start = 8,
        .end = 8
    },
    {
        .start = 8,
        .end = 8
    },
    {
        .start = 8,
        .end = 8
    },
    {
        .start = 9,
        .end = 9
    },
    {
        .start = 9,
        .end = 9
    },
    {
        .start = 9,
        .end = 9
    },
    {
        .start = 9,
        .end = 9
    },
    {
        .start = 9,
        .end = 9
    },
    {
        .start = 9,
        .end = 9
    },
    {
        .start = 9,
        .end = 9
    },
    {
        .start = 9,
        .end = 9
    },
    {
        .start = 10,
        .end = 13
    },
    {
        .start = 10,
        .end = 13
    },
    {
        .start = 10,
        .end = 13
    },
    {
        .start = 10,
        .end = 13
    },
    {
        .start = 10,
        .end = 13
    },
    {
        .start = 10,
        .end = 13
    },
    {
        .start = 10,
        .end = 13
    },
    {
        .start = 10,
        .end = 13
    },
    {
        .start = 14,
        .end = 18
    },
    {
        .start = 14,
        .end = 18
    },
    {
        .start = 14,
        .end = 18
    },
    {
        .start = 14,
        .end = 18
    },
    {
        .start = 14,
        .end = 18
    },
    {
        .start = 14,
        .end = 18
    },
    {
        .start = 14,
        .end = 18
    },
    {
        .start = 14,
        .end = 18
    }
};

const UWORD sprite_enemy_0_animations_lookup[] = {
    SPRITE_2_STATE_DEFAULT,
    SPRITE_2_STATE_FIRING,
    SPRITE_2_STATE_COVER_STANDING,
    SPRITE_2_STATE_COVER_CROUCHING,
    SPRITE_2_STATE_COVER_STANDING_FIRING,
    SPRITE_2_STATE_ROLLING
};

const struct spritesheet_t sprite_enemy_0 = {
    .n_metasprites = 19,
    .emote_origin = {
        .x = 0,
        .y = -32
    },
    .metasprites = sprite_enemy_0_metasprites,
    .animations = sprite_enemy_0_animations,
    .animations_lookup = sprite_enemy_0_animations_lookup,
    .bounds = {
        .left = 3,
        .bottom = 3,
        .right = 12,
        .top = -20
    },
    .tileset = TO_FAR_PTR_T(sprite_enemy_0_tileset),
    .cgb_tileset = { NULL, NULL }
};
