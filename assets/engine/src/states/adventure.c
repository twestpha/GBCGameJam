#pragma bank 255

#include "data/states_defines.h"
#include "states/adventure.h"

#include "actor.h"
#include "camera.h"
#include "collision.h"
#include "game_time.h"
#include "input.h"
#include "scroll.h"
#include "trigger.h"
#include "data_manager.h"
#include "rand.h"
#include "vm.h"
#include "math.h"
#include "vm_gameboy.h"

#ifndef ADVENTURE_CAMERA_DEADZONE
#define ADVENTURE_CAMERA_DEADZONE 8
#endif

#define VAR_TEMP 18

typedef enum  {
    LEFT_0 = 0,
    LEFT_1 = 1,
    LEFT_2 = 2,
    LEFT_3 = 3,
    CENTER_0 = 4,
    CENTER_1 = 5,
    CENTER_2 = 6,
    CENTER_3 = 7,
    RIGHT_0 = 8,
    RIGHT_1 = 9,
    RIGHT_2 = 10,
    RIGHT_3 = 11,
} aim_block_read;

typedef enum {
    EMPTY = 0,
    WALL  = 1,
    CRATE = 2,
} block_value_read;

extern const struct tileset_t bg_aim_background_tileset_tileset;

void adventure_init() BANKED {
    // Set camera to follow player
    camera_offset_x = 0;
    camera_offset_y = 0;
    camera_deadzone_x = ADVENTURE_CAMERA_DEADZONE;
    camera_deadzone_y = ADVENTURE_CAMERA_DEADZONE;

    // probably set aside some variables to for debugging so you can print them in editor
    // tileset_t* test = TO_FAR_PTR_T(bg_aim_background_tileset_tileset);
    // scene.background.bank and scene.background.tileset

    // vm_set_const(0, VAR_TEMP, wall_tiles[0]);

    // Drawing left-hand columns
    // uint8_t indexOffset = 0;
    // uint8_t x = 0;
    // uint8_t height = 14;
    // uint8_t height_offset = 2;

    // Get previous scene's tileset
    // scene_t scn;
    // background_t bg;
    // far_ptr_t tilesetPtr;
    // tileset_t tileset;

    // MemcpyBanked(&scn, (scene_t*) previous_scene.ptr, sizeof(scn), previous_scene.bank);
    // MemcpyBanked(&bg, scn.background.ptr, sizeof(bg), scn.background.bank);
    //
    // tilesetPtr = bg.tileset;

    // typedef struct tileset_t {
    //     uint16_t n_tiles;                  // actual amount of 8x8 tiles in tiles[] array
    //     uint8_t tiles[];
    // } tileset_t;

    // Double copy, first to get the n_tiles value, then to do the full copy
    // MemcpyBanked(&tileset, bg.tileset.ptr, sizeof(tileset), bg.tileset.bank);
    // MemcpyBanked(&tileset, bg.tileset.ptr, sizeof(uint16_t) + 64, bg.tileset.bank);

    // void vm_replace_tile_xy(
    //     SCRIPT_CTX * THIS,
    //     UBYTE x,
    //     UBYTE y,
    //     UBYTE tileset_bank,
    //     const tileset_t * tileset,
    //     INT16 idx_start_tile
    // );

    // So my 'bug' is that it seems like I'm accessing the right tileset,
    // since this
    // vm_set_const(0, VAR_TEMP, tileset.n_tiles);
    // prints out '31' which is the correct number of tiles for that scene - see
    // bg_aim_background_tileset_tileset.c for reference on that number.
    //
    // But, then accessing the tiles array fucks up... I wonder if that has
    // something to do with unknown array indices...? Like, it's not copying
    // That data over? not sure...

    // This should be 0xFF (or 255)
    // vm_set_const(0, VAR_TEMP, tileset.tiles[16]);
    // but it instead prints 0 consistently...

    // What aboutthis, which should be 0x70 (112)
    // vm_set_const(0, VAR_TEMP, tileset.tiles[19]);
    // This gives 0xC0 (192)...

    // Lets say we're fucked up and somehow in column 7 of the tileset... dunno why
    // But here's that column:
    // 0x00, 0x80, 0x00, 0xC0, 0x00, 0xE0, 0x00, 0xF0,
    // Where thats the 3rd element and previously it was the 0th element...
    // So testing this might give 0xE0 (224)
    // vm_set_const(0, VAR_TEMP, tileset.tiles[21]);
    // This gives 0xB7 (183)... shit...?
    // This is unused at all in the array

    // So, something isn't quite right with the array, that's my guess
    // Can I do all this without a memcopy? Maybe that's the way to do this...

    // I know there's something out there with
    // const struct tileset_t bg_aim_background_tileset_tileset = {
    //     .n_tiles = 31,
    //     .tiles = {
    // and I'd love to just pass this into vm_replace_tile_xy directly but this
    // compiler doesn't know about it... does it?

    // Here's testing reading the above variable bg_aim_background_tileset_tileset
    // Above, like so: extern const struct tileset_t bg_aim_background_tileset_tileset;
    // to see if it has it's values set properly...
    // vm_set_const(0, VAR_TEMP, bg_aim_background_tileset_tileset.n_tiles);
    // This gives 0xFFFFFFFFFFFFCD34 (-13004) which I gotta say is a little weird...

    // So that didn't really work,
    // vm_set_const(0, VAR_TEMP, (UBYTE)(void*)(&bg_aim_background_tileset_tileset));
    // gives 137 and I'm fucked if I know what that means lol



    // vm_set_const(0, VAR_TEMP, bg_aim_background_tileset_tileset.tiles[16]);

    // vm_replace_tile_xy(0, 0, 2, tilesetPtr.bank, &tileset, 1);

    // Iterate stuff here
    // for(uint8_t t = 0; t < 4; t++){
    //     if(wall_tiles[t] == WALL){
    //         for(uint8_t y = 0; y < height; y++){
    //             // vm_replace_tile_xy(0, x, y+height_offset, tileset.bank, (tileset_t*) tileset.ptr, 10);
    //             // vm_replace_tile_xy(0, x+1, y+height_offset, ?, ?, 10);
    //             // vm_replace_tile_xy(0, x+2, y+height_offset, ?, ?, 10);
    //             // vm_replace_tile_xy(0, x+3, y+height_offset, ?, ?, 10);
    //         }
    //
    //         x += 4;
    //     } else {
    //         // Draw side wall (?)
    //
    //         if(wall_tiles[t] == CRATE){
    //             // Draw crates on top of it
    //         }
    //     }
    // }
}

void adventure_update() BANKED {
    actor_t *hit_actor;
    UBYTE tile_start, tile_end;
    UBYTE angle = 0;
    direction_e new_dir = DIR_NONE;

    player_moving = FALSE;

    if (INPUT_RECENT_LEFT) {
        new_dir = DIR_LEFT;
    } else if (INPUT_RECENT_RIGHT) {
        new_dir = DIR_RIGHT;
    } else if (INPUT_RECENT_UP) {
        new_dir = DIR_UP;
    } else if (INPUT_RECENT_DOWN) {
        new_dir = DIR_DOWN;
    }

    if (INPUT_LEFT) {
        player_moving = TRUE;
        if (INPUT_UP) {
            angle = ANGLE_315DEG;
        } else if (INPUT_DOWN) {
            angle = ANGLE_225DEG;
        } else {
            angle = ANGLE_270DEG;
        }
    } else if (INPUT_RIGHT) {
        player_moving = TRUE;
        if (INPUT_UP) {
            angle = ANGLE_45DEG;
        } else if (INPUT_DOWN) {
            angle = ANGLE_135DEG;
        } else {
            angle = ANGLE_90DEG;
        }
    } else if (INPUT_UP) {
        player_moving = TRUE;
        angle = ANGLE_0DEG;
    } else if (INPUT_DOWN) {
        player_moving = TRUE;
        angle = ANGLE_180DEG;
    }

    if (player_moving) {
        upoint16_t new_pos;
        new_pos.x = PLAYER.pos.x;
        new_pos.y = PLAYER.pos.y;
        point_translate_angle(&new_pos, angle, PLAYER.move_speed);

        // Step X
        tile_start = (((PLAYER.pos.y >> 4) + PLAYER.bounds.top)    >> 3);
        tile_end   = (((PLAYER.pos.y >> 4) + PLAYER.bounds.bottom) >> 3) + 1;
        if (angle < ANGLE_180DEG) {
            UBYTE tile_x = ((new_pos.x >> 4) + PLAYER.bounds.right) >> 3;
            while (tile_start != tile_end) {

                if (tile_at(tile_x, tile_start) & COLLISION_LEFT) {
                    new_pos.x = (((tile_x << 3) - PLAYER.bounds.right) << 4) - 1;
                    break;
                }
                tile_start++;
            }
            PLAYER.pos.x = MIN((image_width - 16) << 4, new_pos.x);
        } else {
            UBYTE tile_x = ((new_pos.x >> 4) + PLAYER.bounds.left) >> 3;
            while (tile_start != tile_end) {
                if (tile_at(tile_x, tile_start) & COLLISION_RIGHT) {
                    new_pos.x = ((((tile_x + 1) << 3) - PLAYER.bounds.left) << 4) + 1;
                    break;
                }
                tile_start++;
            }
            PLAYER.pos.x = MAX(0, (WORD)new_pos.x);
        }

        // Step Y
        tile_start = (((PLAYER.pos.x >> 4) + PLAYER.bounds.left)  >> 3);
        tile_end   = (((PLAYER.pos.x >> 4) + PLAYER.bounds.right) >> 3) + 1;
        if (angle > ANGLE_90DEG && angle < ANGLE_270DEG) {
            UBYTE tile_y = ((new_pos.y >> 4) + PLAYER.bounds.bottom) >> 3;
            while (tile_start != tile_end) {
                if (tile_at(tile_start, tile_y) & COLLISION_TOP) {
                    new_pos.y = ((((tile_y) << 3) - PLAYER.bounds.bottom) << 4) - 1;
                    break;
                }
                tile_start++;
            }
            PLAYER.pos.y = new_pos.y;
        } else {
            UBYTE tile_y = (((new_pos.y >> 4) + PLAYER.bounds.top) >> 3);
            while (tile_start != tile_end) {
                if (tile_at(tile_start, tile_y) & COLLISION_BOTTOM) {
                    new_pos.y = ((((UBYTE)(tile_y + 1) << 3) - PLAYER.bounds.top) << 4) + 1;
                    break;
                }
                tile_start++;
            }
            PLAYER.pos.y = new_pos.y;
        }
    }

    if (new_dir != DIR_NONE) {
        actor_set_dir(&PLAYER, new_dir, player_moving);
    } else {
        actor_set_anim_idle(&PLAYER);
    }

    hit_actor = NULL;
    if (IS_FRAME_ODD) {
        // Check for trigger collisions
        if (trigger_activate_at_intersection(&PLAYER.bounds, &PLAYER.pos, FALSE)) {
            // Landed on a trigger
            return;
        }

        // Check for actor collisions
        hit_actor = actor_overlapping_player(FALSE);
        if (hit_actor != NULL && hit_actor->collision_group) {
            player_register_collision_with(hit_actor);
        }
    }

    if (INPUT_A_PRESSED) {
        if (!hit_actor) {
            hit_actor = actor_in_front_of_player(8, TRUE);
        }
        if (hit_actor && !hit_actor->collision_group && hit_actor->script.bank) {
            script_execute(hit_actor->script.bank, hit_actor->script.ptr, 0, 1, 0);
        }
    }
}
