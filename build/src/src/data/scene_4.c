#pragma bank 255

// Scene: aim_background_tileset

#include "gbs_types.h"
#include "data/bg_aim_background_tileset.h"
#include "data/scene_4_collisions.h"
#include "data/palette_2.h"
#include "data/palette_6.h"
#include "data/sprite_enemy_projectile.h"
#include "data/scene_4_init.h"

BANKREF(scene_4)

const struct scene_t scene_4 = {
    .width = 32,
    .height = 32,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(bg_aim_background_tileset),
    .collisions = TO_FAR_PTR_T(scene_4_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_2),
    .sprite_palette = TO_FAR_PTR_T(palette_6),
    .reserve_tiles = 0,
    .player_sprite = TO_FAR_PTR_T(sprite_enemy_projectile),
    .n_actors = 0,
    .n_triggers = 0,
    .n_sprites = 0,
    .n_projectiles = 0,
    .script_init = TO_FAR_PTR_T(scene_4_init)
};
