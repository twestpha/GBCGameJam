.module actor_5_update

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

.LOCAL_ACTOR = -4

___bank_actor_5_update = 255
.globl ___bank_actor_5_update

_actor_5_update::
        VM_RESERVE              4

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
        VM_SET                  VAR_S2A0_LOCAL_0, .ARG1
        VM_SET                  VAR_S2A0_LOCAL_1, .ARG0
        VM_POP                  2

        ; Variable L1 = VAR_S2A0_LOCAL_1+8
        VM_RPN
            .R_REF      VAR_S2A0_LOCAL_1
            .R_INT16    8
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  VAR_S2A0_LOCAL_1, .ARG0
        VM_POP                  1

        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 1

        ; Actor Set Position To Variables
        VM_RPN
            .R_REF      VAR_S2A0_LOCAL_0
            .R_INT16    16
            .R_OPERATOR .MUL
            .R_REF      VAR_S2A0_LOCAL_1
            .R_INT16    16
            .R_OPERATOR .MUL
            .R_STOP
        VM_SET                  ^/(.LOCAL_ACTOR + 1 - 2)/, .ARG1
        VM_SET                  ^/(.LOCAL_ACTOR + 2 - 2)/, .ARG0
        VM_POP                  2
        VM_ACTOR_SET_POS        .LOCAL_ACTOR

        ; Idle
        VM_IDLE

        VM_JUMP                 1$
        ; Stop Script
        VM_STOP
