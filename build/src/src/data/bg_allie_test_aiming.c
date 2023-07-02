#pragma bank 255

// Background: aim_background

#include "gbs_types.h"
#include "data/bg_allie_test_aiming_tileset.h"
#include "data/bg_allie_test_aiming_tilemap.h"
#include "data/bg_allie_test_aiming_tilemap_attr.h"

BANKREF(bg_allie_test_aiming)

const struct background_t bg_allie_test_aiming = {
    .width = 20,
    .height = 18,
    .tileset = TO_FAR_PTR_T(bg_allie_test_aiming_tileset),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(bg_allie_test_aiming_tilemap),
    .cgb_tilemap_attr = TO_FAR_PTR_T(bg_allie_test_aiming_tilemap_attr)
};
