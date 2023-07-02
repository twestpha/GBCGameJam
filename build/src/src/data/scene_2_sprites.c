#pragma bank 255

// Scene: aim_background
// Sprites

#include "gbs_types.h"
#include "data/sprite_player_aiming.h"
#include "data/sprite_enemy_0.h"
#include "data/sprite_blood_fx.h"
#include "data/sprite_enemy_projectile.h"

BANKREF(scene_2_sprites)

const far_ptr_t scene_2_sprites[] = {
    TO_FAR_PTR_T(sprite_player_aiming),
    TO_FAR_PTR_T(sprite_enemy_0),
    TO_FAR_PTR_T(sprite_blood_fx),
    TO_FAR_PTR_T(sprite_enemy_projectile)
};
