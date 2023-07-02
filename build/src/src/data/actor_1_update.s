.module actor_1_update

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

.LOCAL_TMP0_INPUT = -4
.LOCAL_ACTOR = -4
.LOCAL_TMP2_INPUT = -5

___bank_actor_1_update = 255
.globl ___bank_actor_1_update

_actor_1_update::
        VM_RESERVE              5

1$:
        ; If Variable .EQ Value
        VM_IF_CONST             .EQ, VAR_PLAYER_AIM_MODE, 1, 2$, 0
        VM_JUMP                 3$
2$:
        ; If Input
        VM_GET_INT8             .LOCAL_TMP0_INPUT, ^/(_joypads + 1)/
        VM_RPN
            .R_REF      .LOCAL_TMP0_INPUT
            .R_INT8     2
            .R_OPERATOR .B_AND
            .R_STOP
        VM_IF_CONST             .NE, .ARG0, 0, 4$, 1

        VM_JUMP                 5$
4$:
        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 1

        ; Actor Move Relative
        VM_ACTOR_GET_POS        .LOCAL_ACTOR
        VM_RPN
            .R_REF      ^/(.LOCAL_ACTOR + 1)/
            .R_INT16    -96
            .R_OPERATOR .ADD
            .R_INT16    0
            .R_OPERATOR .MAX
            .R_REF      ^/(.LOCAL_ACTOR + 2)/
            .R_INT16    0
            .R_OPERATOR .ADD
            .R_INT16    0
            .R_OPERATOR .MAX
            .R_STOP
        VM_SET                  ^/(.LOCAL_ACTOR + 1 - 2)/, .ARG1
        VM_SET                  ^/(.LOCAL_ACTOR + 2 - 2)/, .ARG0
        VM_POP                  2
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 3)/, ^/(.ACTOR_ATTR_CHECK_COLL | .ACTOR_ATTR_H_FIRST)/
        VM_ACTOR_MOVE_TO        .LOCAL_ACTOR

5$:

        ; If Input
        VM_GET_INT8             .LOCAL_TMP2_INPUT, ^/(_joypads + 1)/
        VM_RPN
            .R_REF      .LOCAL_TMP2_INPUT
            .R_INT8     1
            .R_OPERATOR .B_AND
            .R_STOP
        VM_IF_CONST             .NE, .ARG0, 0, 6$, 1

        VM_JUMP                 7$
6$:
        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 1

        ; Actor Move Relative
        VM_ACTOR_GET_POS        .LOCAL_ACTOR
        VM_RPN
            .R_REF      ^/(.LOCAL_ACTOR + 1)/
            .R_INT16    96
            .R_OPERATOR .ADD
            .R_INT16    0
            .R_OPERATOR .MAX
            .R_REF      ^/(.LOCAL_ACTOR + 2)/
            .R_INT16    0
            .R_OPERATOR .ADD
            .R_INT16    0
            .R_OPERATOR .MAX
            .R_STOP
        VM_SET                  ^/(.LOCAL_ACTOR + 1 - 2)/, .ARG1
        VM_SET                  ^/(.LOCAL_ACTOR + 2 - 2)/, .ARG0
        VM_POP                  2
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 3)/, ^/(.ACTOR_ATTR_CHECK_COLL | .ACTOR_ATTR_H_FIRST)/
        VM_ACTOR_MOVE_TO        .LOCAL_ACTOR

7$:

3$:

        ; Idle
        VM_IDLE

        VM_JUMP                 1$
        ; Stop Script
        VM_STOP
