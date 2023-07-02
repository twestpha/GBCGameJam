.module script_input_4

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255


___bank_script_input_4 = 255
.globl ___bank_script_input_4

_script_input_4::
        ; Stop Script
        VM_STOP
