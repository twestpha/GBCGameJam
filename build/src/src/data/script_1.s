.module script_1

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

.SCRIPT_ARG_0_ACTOR = -8
.LOCAL_ACTOR = -4
.LOCAL_TMP1_WAIT_ARGS = -5

___bank_script_1 = 255
.globl ___bank_script_1

_script_1::
        VM_RESERVE              5

        ; Actor Set Active
        VM_SET                  .LOCAL_ACTOR, .SCRIPT_ARG_0_ACTOR

        ; Actor Set Collisions
        VM_ACTOR_SET_COLL_ENABLED .LOCAL_ACTOR, 0

        ; Actor Set Active
        VM_SET                  .LOCAL_ACTOR, .SCRIPT_ARG_0_ACTOR

        ; Actor Set Position To Variables
        VM_RPN
            .R_REF      VAR_PLAYER_SHOOT_X
            .R_INT16    16
            .R_OPERATOR .MUL
            .R_REF      VAR_PLAYER_SHOOT_Y
            .R_INT16    16
            .R_OPERATOR .MUL
            .R_STOP
        VM_SET                  ^/(.LOCAL_ACTOR + 1 - 2)/, .ARG1
        VM_SET                  ^/(.LOCAL_ACTOR + 2 - 2)/, .ARG0
        VM_POP                  2
        VM_ACTOR_SET_POS        .LOCAL_ACTOR

        ; Actor Show
        VM_SET                  .LOCAL_ACTOR, .SCRIPT_ARG_0_ACTOR
        VM_ACTOR_SET_HIDDEN     .LOCAL_ACTOR, 0

        ; Actor Set Active
        VM_SET                  .LOCAL_ACTOR, .SCRIPT_ARG_0_ACTOR

        ; Actor Set Animation Frame
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 1)/, 0
        VM_ACTOR_SET_ANIM_FRAME .LOCAL_ACTOR

        ; Wait N Frames
        VM_SET_CONST            .LOCAL_TMP1_WAIT_ARGS, 15
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP1_WAIT_ARGS

        ; Actor Hide
        VM_SET                  .LOCAL_ACTOR, .SCRIPT_ARG_0_ACTOR
        VM_ACTOR_SET_HIDDEN     .LOCAL_ACTOR, 1

        VM_RESERVE              -5
        VM_RET_FAR_N            1
