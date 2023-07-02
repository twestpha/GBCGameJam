#pragma bank 255

// Scene: level_0_test
// Sprites

#include "gbs_types.h"
#include "data/sprite_enemy_0.h"

BANKREF(scene_1_sprites)

const far_ptr_t scene_1_sprites[] = {
    TO_FAR_PTR_T(sprite_enemy_0)
};
