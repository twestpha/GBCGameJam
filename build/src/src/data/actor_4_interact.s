.module actor_4_interact

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

.LOCAL_TMP0_PARAM0_VALUE = -1

___bank_actor_4_interact = 255
.globl ___bank_actor_4_interact

_actor_4_interact::
        VM_RESERVE              1

        ; If Parameter 0 Equals 2
        VM_GET_TLOCAL           .LOCAL_TMP0_PARAM0_VALUE, 0
        VM_IF_CONST             .EQ, .LOCAL_TMP0_PARAM0_VALUE, 2, 1$, 0
        VM_JUMP                 2$
1$:
        ; Call Script: spawn_blood
        VM_PUSH_CONST           3 ; Actor 0
        VM_CALL_FAR             ___bank_script_1, _script_1

        ; Stop Script
        VM_STOP
2$:

        ; Stop Script
        VM_STOP
