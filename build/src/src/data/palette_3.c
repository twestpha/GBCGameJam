#pragma bank 255

// Palette: 3

#include "gbs_types.h"

BANKREF(palette_3)

const struct palette_t palette_3 = {
    .mask = 0xFF,
    .palette = {
        DMG_PALETTE(DMG_WHITE, DMG_WHITE, DMG_LITE_GRAY, DMG_BLACK),
        DMG_PALETTE(DMG_WHITE, DMG_WHITE, DMG_DARK_GRAY, DMG_BLACK)
    },
    .cgb_palette = {
        CGB_PALETTE(RGB(28, 31, 20), RGB(28, 31, 20), RGB(15, 25, 7), RGB(1, 3, 1)),
        CGB_PALETTE(RGB(31, 30, 28), RGB(31, 30, 28), RGB(27, 16, 15), RGB(0, 0, 1)),
        CGB_PALETTE(RGB(31, 30, 28), RGB(31, 30, 28), RGB(27, 16, 15), RGB(0, 0, 1)),
        CGB_PALETTE(RGB(31, 30, 28), RGB(31, 30, 28), RGB(27, 16, 15), RGB(0, 0, 1)),
        CGB_PALETTE(RGB(31, 30, 28), RGB(31, 30, 28), RGB(27, 16, 15), RGB(0, 0, 1)),
        CGB_PALETTE(RGB(31, 30, 28), RGB(31, 30, 28), RGB(27, 16, 15), RGB(0, 0, 1)),
        CGB_PALETTE(RGB(31, 30, 28), RGB(31, 30, 28), RGB(27, 16, 15), RGB(0, 0, 1)),
        CGB_PALETTE(RGB(31, 30, 28), RGB(31, 30, 28), RGB(27, 16, 15), RGB(0, 0, 1))
    }
};
