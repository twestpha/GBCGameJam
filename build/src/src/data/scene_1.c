#pragma bank 255

// Scene: level_0_test

#include "gbs_types.h"
#include "data/bg_allie_test_map.h"
#include "data/scene_1_collisions.h"
#include "data/palette_0.h"
#include "data/palette_3.h"
#include "data/sprite_allie_test_player_2.h"
#include "data/scene_1_actors.h"
#include "data/scene_1_sprites.h"
#include "data/scene_1_init.h"

BANKREF(scene_1)

const struct scene_t scene_1 = {
    .width = 32,
    .height = 32,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(bg_allie_test_map),
    .collisions = TO_FAR_PTR_T(scene_1_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_0),
    .sprite_palette = TO_FAR_PTR_T(palette_3),
    .reserve_tiles = 0,
    .player_sprite = TO_FAR_PTR_T(sprite_allie_test_player_2),
    .n_actors = 1,
    .n_triggers = 0,
    .n_sprites = 1,
    .n_projectiles = 0,
    .actors = TO_FAR_PTR_T(scene_1_actors),
    .sprites = TO_FAR_PTR_T(scene_1_sprites),
    .script_init = TO_FAR_PTR_T(scene_1_init)
};
