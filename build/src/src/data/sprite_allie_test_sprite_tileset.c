#pragma bank 255

// Tileset: sprite_allie_test_sprite_tileset

#include "gbs_types.h"

BANKREF(sprite_allie_test_sprite_tileset)

const struct tileset_t sprite_allie_test_sprite_tileset = {
    .n_tiles = 4,
    .tiles = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x60, 0x00, 0x10, 0x00, 0x10, 0x00, 0x08, 0x00, 0xFC,
        0x00, 0x08, 0x00, 0x10, 0x00, 0x10, 0x00, 0x60, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0x00, 0x0D, 0x00, 0x11, 0x00, 0x11, 0x00, 0x21, 0x00, 0x7F,
        0x00, 0x21, 0x00, 0x11, 0x00, 0x11, 0x00, 0x0D, 0x00, 0x03, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00
    }
};
