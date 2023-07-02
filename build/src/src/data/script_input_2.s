.module script_input_2

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

.LOCAL_ACTOR = -4
.LOCAL_TMP1_WAIT_ARGS = -4

___bank_script_input_2 = 255
.globl ___bank_script_input_2

_script_input_2::
        VM_RESERVE              4

        ; If Variable .EQ Value
        VM_IF_CONST             .EQ, VAR_PLAYER_AIM_MODE, 0, 1$, 0
        VM_JUMP                 2$
1$:
        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 0

        ; Store Position In Variables
        VM_ACTOR_GET_POS        .LOCAL_ACTOR
        VM_RPN
            .R_REF      ^/(.LOCAL_ACTOR + 1)/
            .R_INT16    16
            .R_OPERATOR .DIV
            .R_REF      ^/(.LOCAL_ACTOR + 2)/
            .R_INT16    16
            .R_OPERATOR .DIV
            .R_STOP
        VM_SET                  VAR_PLAYER_SHOOT_X, .ARG1
        VM_SET                  VAR_PLAYER_SHOOT_Y, .ARG0
        VM_POP                  2

        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 0

        ; Launch Projectile In Direction
        VM_ACTOR_GET_POS        .LOCAL_ACTOR
        VM_ACTOR_GET_POS        .LOCAL_ACTOR
        VM_RPN
            .R_REF      ^/(.LOCAL_ACTOR + 1)/
            .R_REF      ^/(.LOCAL_ACTOR + 2)/
            .R_INT16    0
            .R_INT16    .PROJECTILE_ANIM_ONCE
            .R_STOP
        VM_PROJECTILE_LAUNCH    0, .ARG3
        VM_POP                  4

        VM_LOAD_PALETTE         255, ^/(.PALETTE_BKG | .PALETTE_COMMIT)/
        .CGB_PAL                31, 31, 31, 31, 31, 1, 31, 31, 1, 6, 2, 5
        .CGB_PAL                31, 31, 31, 31, 31, 1, 31, 31, 1, 6, 2, 5
        .CGB_PAL                31, 31, 31, 31, 31, 1, 31, 31, 1, 6, 2, 5
        .CGB_PAL                31, 31, 31, 31, 31, 1, 31, 31, 1, 6, 2, 5
        .CGB_PAL                31, 31, 31, 31, 31, 1, 31, 31, 1, 6, 2, 5
        .CGB_PAL                31, 31, 31, 31, 31, 1, 31, 31, 1, 6, 2, 5
        .CGB_PAL                31, 31, 31, 31, 31, 1, 31, 31, 1, 6, 2, 5
        .CGB_PAL                31, 31, 31, 31, 31, 1, 31, 31, 1, 6, 2, 5
        ; Wait N Frames
        VM_SET_CONST            .LOCAL_TMP1_WAIT_ARGS, 4
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP1_WAIT_ARGS

        VM_LOAD_PALETTE         255, ^/(.PALETTE_BKG | .PALETTE_COMMIT)/
        .CGB_PAL                25, 29, 31, 8, 21, 21, 17, 0, 23, 3, 4, 9
        .CGB_PAL                25, 29, 31, 19, 19, 28, 13, 10, 21, 9, 4, 14
        .CGB_PAL                31, 31, 31, 31, 31, 1, 19, 8, 3, 3, 3, 7
        .CGB_PAL                31, 31, 31, 31, 31, 1, 31, 31, 1, 6, 2, 5
        .CGB_PAL                31, 31, 31, 31, 31, 1, 31, 31, 1, 6, 2, 5
        .CGB_PAL                31, 31, 31, 31, 31, 1, 31, 31, 1, 6, 2, 5
        .CGB_PAL                31, 31, 31, 31, 31, 1, 31, 31, 1, 6, 2, 5
        .CGB_PAL                31, 31, 31, 31, 31, 1, 31, 31, 1, 6, 2, 5
2$:

        ; Stop Script
        VM_STOP
