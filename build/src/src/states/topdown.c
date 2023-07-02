#pragma bank 255

#include "data/states_defines.h"
#include "states/topdown.h"

#include "actor.h"
#include "camera.h"
#include "collision.h"
#include "data_manager.h"
#include "game_time.h"
#include "input.h"
#include "trigger.h"
#include "math.h"
#include "vm.h"
#include "system.h"

#ifndef INPUT_TOPDOWN_INTERACT
#define INPUT_TOPDOWN_INTERACT INPUT_A
#endif

#define ONE_TILE 256

UBYTE topdown_grid;

typedef enum  {
    LEFT_0,
    LEFT_1,
    LEFT_2,
    LEFT_3,
    CENTER_0,
    CENTER_1,
    CENTER_2,
    CENTER_3,
    RIGHT_0,
    RIGHT_1,
    RIGHT_2,
    RIGHT_3,
} aim_block;

typedef enum {
    EMPTY = 0,
    WALL  = 1,
    CRATE = 2,
} block_value;

void topdown_init() BANKED {
    camera_offset_x = 0;
    camera_offset_y = 0;
    camera_deadzone_x = 0;
    camera_deadzone_y = 0;

    if (topdown_grid == 16) {
        // Snap to 16px grid
        PLAYER.pos.x = ((PLAYER.pos.x >> 8) << 8);
        PLAYER.pos.y = ((PLAYER.pos.y >> 8) << 8) + 128;
    } else {
        PLAYER.pos.x = ((PLAYER.pos.x >> 7) << 7);
        PLAYER.pos.y = ((PLAYER.pos.y >> 7) << 7);
    }
}

void topdown_update() BANKED {
    actor_t *hit_actor;
    UBYTE tile_start, tile_end;
    direction_e new_dir = DIR_NONE;

    // Is player on an 8x8px tile?
    if ((topdown_grid == 16 && ON_16PX_GRID(PLAYER.pos)) ||
        (topdown_grid == 8 && ON_8PX_GRID(PLAYER.pos))) {
        // Player landed on an tile
        // so stop movement for now
        player_moving = FALSE;

        // Check for trigger collisions
        if (trigger_activate_at_intersection(&PLAYER.bounds, &PLAYER.pos, FALSE)) {
            // Landed on a trigger
            return;
        }

        // Check input to set player movement
        if (INPUT_RECENT_LEFT) {
            player_moving = TRUE;
            new_dir = DIR_LEFT;

            // Check for collisions to left of player
            tile_start = (((PLAYER.pos.y >> 4) + PLAYER.bounds.top)    >> 3);
            tile_end   = (((PLAYER.pos.y >> 4) + PLAYER.bounds.bottom) >> 3) + 1;
            UBYTE tile_x = ((PLAYER.pos.x >> 4) + PLAYER.bounds.left) >> 3;
            while (tile_start != tile_end) {
                if (tile_at(tile_x - 1, tile_start) & COLLISION_RIGHT) {
                    player_moving = FALSE;
                    break;
                }
                tile_start++;
            }
        } else if (INPUT_RECENT_RIGHT) {
            player_moving = TRUE;
            new_dir = DIR_RIGHT;

            // Check for collisions to right of player
            tile_start = (((PLAYER.pos.y >> 4) + PLAYER.bounds.top)    >> 3);
            tile_end   = (((PLAYER.pos.y >> 4) + PLAYER.bounds.bottom) >> 3) + 1;
            UBYTE tile_x = ((PLAYER.pos.x >> 4) + PLAYER.bounds.right) >> 3;
            while (tile_start != tile_end) {
                if (tile_at(tile_x + 1, tile_start) & COLLISION_LEFT) {
                    player_moving = FALSE;
                    break;
                }
                tile_start++;
            }
        } else if (INPUT_RECENT_UP) {
            player_moving = TRUE;
            new_dir = DIR_UP;

            // Check for collisions below player
            tile_start = (((PLAYER.pos.x >> 4) + PLAYER.bounds.left)  >> 3);
            tile_end   = (((PLAYER.pos.x >> 4) + PLAYER.bounds.right) >> 3) + 1;
            UBYTE tile_y = ((PLAYER.pos.y >> 4) + PLAYER.bounds.top) >> 3;
            while (tile_start != tile_end) {
                if (tile_at(tile_start, tile_y - 1) & COLLISION_BOTTOM) {
                    player_moving = FALSE;
                    break;
                }
                tile_start++;
            }
        } else if (INPUT_RECENT_DOWN) {
            player_moving = TRUE;
            new_dir = DIR_DOWN;

            // Check for collisions below player
            tile_start = (((PLAYER.pos.x >> 4) + PLAYER.bounds.left)  >> 3);
            tile_end   = (((PLAYER.pos.x >> 4) + PLAYER.bounds.right) >> 3) + 1;
            UBYTE tile_y = ((PLAYER.pos.y >> 4) + PLAYER.bounds.bottom) >> 3;
            while (tile_start != tile_end) {
                if (tile_at(tile_start, tile_y + 1) & COLLISION_TOP) {
                    player_moving = FALSE;
                    break;
                }
                tile_start++;
            }
        }

        // Update direction animation
        if (new_dir != DIR_NONE) {
            actor_set_dir(&PLAYER, new_dir, player_moving);
        } else {
            actor_set_anim_idle(&PLAYER);
        }

        if (IS_FRAME_ODD) {
            // Check for actor overlap
            hit_actor = actor_overlapping_player(FALSE);
            if (hit_actor != NULL && hit_actor->collision_group) {
                player_register_collision_with(hit_actor);
            }
        }

        // Check if walked in to actor
        if (player_moving) {
            hit_actor = actor_in_front_of_player(topdown_grid, FALSE);
            if (hit_actor != NULL) {
                player_register_collision_with(hit_actor);
                actor_stop_anim(&PLAYER);
                player_moving = FALSE;
            }
        }

        if(INPUT_PRESSED(INPUT_START)){
            // Setup right/left origins
            upoint16_t player_center;
            player_center = PLAYER.pos;
            upoint16_t player_right;
            player_right = PLAYER.pos;
            upoint16_t player_left;
            player_left = PLAYER.pos;

            if(PLAYER.dir == DIR_DOWN){
                player_right.x = player_center.x - ONE_TILE;
                player_left.x  = player_center.x + ONE_TILE;
            } else if(PLAYER.dir == DIR_RIGHT){
                player_right.y = player_center.y + ONE_TILE;
                player_left.y  = player_center.y - ONE_TILE;
            } else if(PLAYER.dir == DIR_UP){
                player_right.x = player_center.x + ONE_TILE;
                player_left.x  = player_center.x - ONE_TILE;
            } else if(PLAYER.dir == DIR_LEFT){
                player_right.y = player_center.y - ONE_TILE;
                player_left.y  = player_center.y + ONE_TILE;
            }

            point8_t dir_point;
            dir_point = dir_lookup[PLAYER.dir];

            for(uint8_t i = 0; i < 4; i++){
                // m = 2i, moving by 16px each iteration
                uint8_t m = 2 * i;

                // Test left tiles and write to variables
                UBYTE tile_coll_left_xa = (player_left.x >> 7) + (dir_point.x * m);
                UBYTE tile_coll_left_ya = (player_left.y >> 7) + (dir_point.y * m);

                UBYTE tile_coll_left_xb = (player_left.y >> 7)  + (dir_point.y * m) - 1;

                UBYTE leftCollisionA = tile_at(tile_coll_left_xa, tile_coll_left_ya);
                UBYTE leftCollisionB = tile_at(tile_coll_left_xa, tile_coll_left_xb);

                if(leftCollisionA != leftCollisionB){
                    a_wall_tiles[i] = CRATE;
                    // vm_set_const(0, LEFT_0 + i, CRATE);
                } else if(leftCollisionA){
                    a_wall_tiles[i] = WALL;
                    // vm_set_const(0, LEFT_0 + i, WALL);
                } else {
                    a_wall_tiles[i] = EMPTY;
                    // vm_set_const(0, LEFT_0 + i, EMPTY);
                }

                // Test center tiles and write to variables
                UBYTE tile_coll_center_xa = (player_center.x >> 7) + (dir_point.x * m);
                UBYTE tile_coll_center_ya = (player_center.y >> 7) + (dir_point.y * m);

                UBYTE tile_coll_center_xb = (player_center.y >> 7)  + (dir_point.y * m) - 1;

                UBYTE centerCollisionA = tile_at(tile_coll_center_xa, tile_coll_center_ya);
                UBYTE centerCollisionB = tile_at(tile_coll_center_xa, tile_coll_center_xb);

                if(centerCollisionA != centerCollisionB){
                    a_wall_tiles[i] = CRATE;
                    // vm_set_const(0, CENTER_0 + i, CRATE);
                } else if(centerCollisionA){
                    a_wall_tiles[i] = WALL;
                    // vm_set_const(0, CENTER_0 + i, WALL);
                } else {
                    a_wall_tiles[i] = EMPTY;
                    // vm_set_const(0, CENTER_0 + i, EMPTY);
                }

                // Test right tiles and write to variables
                UBYTE tile_coll_right_xa = (player_right.x >> 7) + (dir_point.x * m);
                UBYTE tile_coll_right_ya = (player_right.y >> 7) + (dir_point.y * m);

                UBYTE tile_coll_right_xb = (player_right.y >> 7)  + (dir_point.y * m) - 1;

                UBYTE rightCollisionA = tile_at(tile_coll_right_xa, tile_coll_right_ya);
                UBYTE rightCollisionB = tile_at(tile_coll_right_xa, tile_coll_right_xb);

                if(rightCollisionA != rightCollisionB){
                    a_wall_tiles[i] = CRATE;
                    // vm_set_const(0, RIGHT_0 + i, CRATE);
                } else if(rightCollisionA){
                    a_wall_tiles[i] = WALL;
                    // vm_set_const(0, RIGHT_0 + i, WALL);
                } else {
                    a_wall_tiles[i] = EMPTY;
                    // vm_set_const(0, RIGHT_0 + i, EMPTY);
                }
            }
        }

        if (INPUT_PRESSED(INPUT_TOPDOWN_INTERACT)) {
            hit_actor = actor_in_front_of_player(topdown_grid, TRUE);
            if (hit_actor != NULL && !hit_actor->collision_group) {
                actor_set_dir(hit_actor, FLIPPED_DIR(PLAYER.dir), FALSE);
                player_moving = FALSE;
                if (hit_actor->script.bank) {
                    script_execute(hit_actor->script.bank, hit_actor->script.ptr, 0, 1, 0);
                }
            }
        }
    }

    if (player_moving) point_translate_dir(&PLAYER.pos, PLAYER.dir, PLAYER.move_speed);
}
