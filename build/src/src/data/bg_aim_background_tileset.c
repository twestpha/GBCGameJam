#pragma bank 255

// Background: aim_background_tileset

#include "gbs_types.h"
#include "data/bg_aim_background_tileset_tileset.h"
#include "data/bg_aim_background_tileset_tilemap.h"
#include "data/bg_aim_background_tileset_tilemap_attr.h"

BANKREF(bg_aim_background_tileset)

const struct background_t bg_aim_background_tileset = {
    .width = 32,
    .height = 32,
    .tileset = TO_FAR_PTR_T(bg_aim_background_tileset_tileset),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(bg_aim_background_tileset_tilemap),
    .cgb_tilemap_attr = TO_FAR_PTR_T(bg_aim_background_tileset_tilemap_attr)
};
