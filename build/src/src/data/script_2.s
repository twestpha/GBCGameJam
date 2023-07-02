.module script_2

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255


___bank_script_2 = 255
.globl ___bank_script_2

_script_2::
        VM_RET_FAR
