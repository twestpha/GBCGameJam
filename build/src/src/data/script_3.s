.module script_3

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

.SCRIPT_ARG_INDIRECT_0_VARIABLE = -3
.SCRIPT_ARG_INDIRECT_1_VARIABLE = -4

___bank_script_3 = 255
.globl ___bank_script_3

_script_3::
        ; Variable 27 = $V0$
        VM_RPN
            .R_REF_IND  .SCRIPT_ARG_INDIRECT_0_VARIABLE
            .R_STOP
        VM_SET                  VAR_COLUMN_DRAW_X, .ARG0
        VM_POP                  1

        ; Variable 26 = (18-$V1$)/2
        VM_RPN
            .R_INT16    18
            .R_REF_IND  .SCRIPT_ARG_INDIRECT_1_VARIABLE
            .R_OPERATOR .SUB
            .R_INT16    2
            .R_OPERATOR .DIV
            .R_STOP
        VM_SET                  VAR_DRAW_Y_OFFSET, .ARG0
        VM_POP                  1

        ; Variable 23 = $V1$
        VM_RPN
            .R_REF_IND  .SCRIPT_ARG_INDIRECT_1_VARIABLE
            .R_STOP
        VM_SET                  VAR_ITERATOR, .ARG0
        VM_POP                  1

        ; While VAR_ITERATOR>=0
1$:
        VM_RPN
            .R_REF      VAR_ITERATOR
            .R_INT16    0
            .R_OPERATOR .GTE
            .R_STOP
        VM_IF_CONST             .EQ, .ARG0, 0, 2$, 1
        ; Variable 24 = VAR_ITERATOR+VAR_DRAW_Y_OFFSET
        VM_RPN
            .R_REF      VAR_ITERATOR
            .R_REF      VAR_DRAW_Y_OFFSET
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  VAR_TEMP, .ARG0
        VM_POP                  1

        ; butts
        VM_REPLACE_TILE_XY .R_INT8 VAR_COLUMN_DRAW_X, .R_INT8 VAR_TEMP, ___bank_bg_aim_background_tileset_tileset, _bg_aim_background_tileset_tileset, #3

        ; Text Dialogue
        VM_LOAD_TEXT            2
        .dw VAR_COLUMN_DRAW_X, VAR_TEMP
        .asciz "x: %d y: %d"
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Variable Decrement By 1
        VM_RPN
            .R_REF      VAR_ITERATOR
            .R_INT8     1
            .R_OPERATOR .SUB
            .R_STOP
        VM_SET                  VAR_ITERATOR, .ARG0
        VM_POP                  1

        VM_JUMP                 1$
2$:

        VM_RET_FAR_N            2
