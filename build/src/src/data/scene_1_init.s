.module scene_1_init

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames, _fade_frames_per_step

.area _CODE_255

.LOCAL_ACTOR = -4
.LOCAL_TMP1_WAIT_ARGS = -4

___bank_scene_1_init = 255
.globl ___bank_scene_1_init

_scene_1_init::
        VM_LOCK

        VM_RESERVE              4

        ; Variable Set To False
        VM_SET_CONST            VAR_AIM_BLOCK_LEFT_0, 0

        ; Variable Set To False
        VM_SET_CONST            VAR_AIM_BLOCK_LEFT_1, 0

        ; Variable Set To False
        VM_SET_CONST            VAR_AIM_BLOCK_LEFT_2, 0

        ; Variable Set To False
        VM_SET_CONST            VAR_AIM_BLOCK_LEFT_3, 0

        ; Variable Set To False
        VM_SET_CONST            VAR_AIM_BLOCK_CENTER_0, 0

        ; Variable Set To False
        VM_SET_CONST            VAR_AIM_BLOCK_CENTER_1, 0

        ; Variable Set To False
        VM_SET_CONST            VAR_AIM_BLOCK_CENTER_2, 0

        ; Variable Set To False
        VM_SET_CONST            VAR_AIM_BLOCK_CENTER_3, 0

        ; Variable Set To False
        VM_SET_CONST            VAR_AIM_BLOCK_RIGHT_0, 0

        ; Variable Set To False
        VM_SET_CONST            VAR_AIM_BLOCK_RIGHT_1, 0

        ; Variable Set To False
        VM_SET_CONST            VAR_AIM_BLOCK_RIGHT_2, 0

        ; Variable Set To False
        VM_SET_CONST            VAR_AIM_BLOCK_RIGHT_3, 0

        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 0

        ; Actor Set Collisions
        VM_ACTOR_SET_COLL_ENABLED .LOCAL_ACTOR, 1

        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 0

        ; Actor Set Movement Speed
        VM_ACTOR_SET_MOVE_SPEED .LOCAL_ACTOR, 16

        ; If Variable .GT Value
        VM_IF_CONST             .GT, VAR_PLAYER_MOVEMENT_X, 0, 1$, 0
        VM_JUMP                 2$
1$:
        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 0

        ; Actor Set Position To Variables
        VM_RPN
            .R_REF      VAR_PLAYER_MOVEMENT_X
            .R_INT16    128
            .R_OPERATOR .MUL
            .R_REF      VAR_PLAYER_MOVEMENT_Y
            .R_INT16    128
            .R_OPERATOR .MUL
            .R_STOP
        VM_SET                  ^/(.LOCAL_ACTOR + 1 - 2)/, .ARG1
        VM_SET                  ^/(.LOCAL_ACTOR + 2 - 2)/, .ARG0
        VM_POP                  2
        VM_ACTOR_SET_POS        .LOCAL_ACTOR

        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 0

        ; Actor Set Direction To Variable
        VM_IF_CONST             .EQ, VAR_PLAYER_MOVEMENT_DIRECTI, .DIR_LEFT, 3$, 0
        VM_IF_CONST             .EQ, VAR_PLAYER_MOVEMENT_DIRECTI, .DIR_RIGHT, 4$, 0
        VM_IF_CONST             .EQ, VAR_PLAYER_MOVEMENT_DIRECTI, .DIR_UP, 5$, 0
        VM_ACTOR_SET_DIR        .LOCAL_ACTOR, .DIR_DOWN
        VM_JUMP                 6$
3$:
        VM_ACTOR_SET_DIR        .LOCAL_ACTOR, .DIR_LEFT
        VM_JUMP                 6$
4$:
        VM_ACTOR_SET_DIR        .LOCAL_ACTOR, .DIR_RIGHT
        VM_JUMP                 6$
5$:
        VM_ACTOR_SET_DIR        .LOCAL_ACTOR, .DIR_UP
6$:

2$:

        ; Input Script Attach
        VM_CONTEXT_PREPARE      1, ___bank_script_input_0, _script_input_0
        VM_INPUT_ATTACH         128, 1

        ; Wait N Frames
        VM_SET_CONST            .LOCAL_TMP1_WAIT_ARGS, 1
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP1_WAIT_ARGS

        ; Fade In
        VM_SET_CONST_INT8       _fade_frames_per_step, 1
        VM_FADE_IN              1

        ; Stop Script
        VM_STOP
