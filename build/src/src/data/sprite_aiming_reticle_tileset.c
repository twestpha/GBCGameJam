#pragma bank 255

// Tileset: sprite_aiming_reticle_tileset

#include "gbs_types.h"

BANKREF(sprite_aiming_reticle_tileset)

const struct tileset_t sprite_aiming_reticle_tileset = {
    .n_tiles = 2,
    .tiles = {
        0xC0, 0xC0, 0x7E, 0xFE, 0x62, 0xFE, 0x7A, 0xFE, 0xCA, 0xCE, 0xCE, 0xCE, 0x7F, 0xFF, 0x31, 0xFF,
        0x7F, 0xFF, 0xCE, 0xCE, 0xCA, 0xCE, 0x7A, 0xFE, 0x62, 0xFE, 0x7E, 0xFE, 0xC0, 0xC0, 0x00, 0x00
    }
};
