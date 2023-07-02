#pragma bank 255

// Scene: aim_background

#include "gbs_types.h"
#include "data/bg_allie_test_aiming.h"
#include "data/scene_2_collisions.h"
#include "data/palette_0.h"
#include "data/palette_4.h"
#include "data/sprite_aiming_reticle.h"
#include "data/scene_2_actors.h"
#include "data/scene_2_sprites.h"
#include "data/scene_2_projectiles.h"
#include "data/scene_2_init.h"

BANKREF(scene_2)

const struct scene_t scene_2 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_ADVENTURE,
    .background = TO_FAR_PTR_T(bg_allie_test_aiming),
    .collisions = TO_FAR_PTR_T(scene_2_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_0),
    .sprite_palette = TO_FAR_PTR_T(palette_4),
    .reserve_tiles = 0,
    .player_sprite = TO_FAR_PTR_T(sprite_aiming_reticle),
    .n_actors = 3,
    .n_triggers = 0,
    .n_sprites = 4,
    .n_projectiles = 2,
    .actors = TO_FAR_PTR_T(scene_2_actors),
    .sprites = TO_FAR_PTR_T(scene_2_sprites),
    .projectiles = TO_FAR_PTR_T(scene_2_projectiles),
    .script_init = TO_FAR_PTR_T(scene_2_init)
};
