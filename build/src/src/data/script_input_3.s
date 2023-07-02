.module script_input_3

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

.LOCAL_ACTOR = -4

___bank_script_input_3 = 255
.globl ___bank_script_input_3

_script_input_3::
        VM_RESERVE              4

        ; If Variable .EQ Value
        VM_IF_CONST             .EQ, VAR_PLAYER_AIM_MODE, 0, 1$, 0
        ; Variable Set To False
        VM_SET_CONST            VAR_PLAYER_AIM_MODE, 0

        ; Actor Show
        VM_SET_CONST            .LOCAL_ACTOR, 0
        VM_ACTOR_SET_HIDDEN     .LOCAL_ACTOR, 0

        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 1

        ; Actor Set Animation State
        VM_ACTOR_SET_ANIM_SET   .LOCAL_ACTOR, STATE_DEFAULT

        ; Input Script Remove
        VM_INPUT_DETACH         15

        VM_JUMP                 2$
1$:
        ; Variable Set To True
        VM_SET_CONST            VAR_PLAYER_AIM_MODE, 1

        ; Actor Hide
        VM_SET_CONST            .LOCAL_ACTOR, 0
        VM_ACTOR_SET_HIDDEN     .LOCAL_ACTOR, 1

        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 1

        ; Actor Set Animation State
        VM_ACTOR_SET_ANIM_SET   .LOCAL_ACTOR, STATE_CROUCHING

        ; Input Script Attach
        VM_CONTEXT_PREPARE      5, ___bank_script_input_4, _script_input_4
        VM_INPUT_ATTACH         15, ^/(5 | .OVERRIDE_DEFAULT)/

2$:

        ; Stop Script
        VM_STOP
