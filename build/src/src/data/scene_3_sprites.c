#pragma bank 255

// Scene: test_lighting_scene
// Sprites

#include "gbs_types.h"
#include "data/sprite_test_light.h"

BANKREF(scene_3_sprites)

const far_ptr_t scene_3_sprites[] = {
    TO_FAR_PTR_T(sprite_test_light)
};
