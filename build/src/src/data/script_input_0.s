.module script_input_0

.include "vm.i"
.include "data/game_globals.i"
.include "macro.i"

.globl _fade_frames_per_step, b_wait_frames, _wait_frames, ___bank_scene_2, _scene_2

.area _CODE_255

.LOCAL_ACTOR = -4
.LOCAL_TMP1_WAIT_ARGS = -5

___bank_script_input_0 = 255
.globl ___bank_script_input_0

_script_input_0::
        VM_RESERVE              5

        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 0

        ; Store Position In Variables
        VM_ACTOR_GET_POS        .LOCAL_ACTOR
        VM_RPN
            .R_REF      ^/(.LOCAL_ACTOR + 1)/
            .R_INT16    128
            .R_OPERATOR .DIV
            .R_REF      ^/(.LOCAL_ACTOR + 2)/
            .R_INT16    128
            .R_OPERATOR .DIV
            .R_STOP
        VM_SET                  VAR_PLAYER_MOVEMENT_X, .ARG1
        VM_SET                  VAR_PLAYER_MOVEMENT_Y, .ARG0
        VM_POP                  2

        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 0

        ; Store Direction In Variable
        VM_ACTOR_GET_DIR        .LOCAL_ACTOR, VAR_PLAYER_MOVEMENT_DIRECTI

        ; Fade Out
        VM_SET_CONST_INT8       _fade_frames_per_step, 3
        VM_FADE_OUT             1

        ; Wait N Frames
        VM_SET_CONST            .LOCAL_TMP1_WAIT_ARGS, 1
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP1_WAIT_ARGS

        ; Load Scene
        VM_SET_CONST_INT8       _fade_frames_per_step, 3
        VM_FADE_OUT             1
        VM_SET_CONST            .LOCAL_ACTOR, 0
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 1)/, 1152
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 2)/, 1280
        VM_ACTOR_SET_POS        .LOCAL_ACTOR
        VM_ACTOR_SET_DIR        .LOCAL_ACTOR, .DIR_DOWN
        VM_RAISE                EXCEPTION_CHANGE_SCENE, 3
            IMPORT_FAR_PTR_DATA _scene_2

        ; Stop Script
        VM_STOP
