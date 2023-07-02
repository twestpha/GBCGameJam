#pragma bank 255

// Scene: test_lighting_scene

#include "gbs_types.h"
#include "data/bg_allie_test_map.h"
#include "data/scene_3_collisions.h"
#include "data/palette_1.h"
#include "data/palette_5.h"
#include "data/sprite_allie_test_player_2.h"
#include "data/scene_3_actors.h"
#include "data/scene_3_sprites.h"
#include "data/scene_3_init.h"

BANKREF(scene_3)

const struct scene_t scene_3 = {
    .width = 32,
    .height = 32,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(bg_allie_test_map),
    .collisions = TO_FAR_PTR_T(scene_3_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_1),
    .sprite_palette = TO_FAR_PTR_T(palette_5),
    .reserve_tiles = 0,
    .player_sprite = TO_FAR_PTR_T(sprite_allie_test_player_2),
    .n_actors = 1,
    .n_triggers = 0,
    .n_sprites = 1,
    .n_projectiles = 0,
    .actors = TO_FAR_PTR_T(scene_3_actors),
    .sprites = TO_FAR_PTR_T(scene_3_sprites),
    .script_init = TO_FAR_PTR_T(scene_3_init)
};
