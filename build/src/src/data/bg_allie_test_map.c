#pragma bank 255

// Background: level_0_background

#include "gbs_types.h"
#include "data/bg_allie_test_map_tileset.h"
#include "data/bg_allie_test_map_tilemap.h"
#include "data/bg_allie_test_map_tilemap_attr.h"

BANKREF(bg_allie_test_map)

const struct background_t bg_allie_test_map = {
    .width = 32,
    .height = 32,
    .tileset = TO_FAR_PTR_T(bg_allie_test_map_tileset),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(bg_allie_test_map_tilemap),
    .cgb_tilemap_attr = TO_FAR_PTR_T(bg_allie_test_map_tilemap_attr)
};
