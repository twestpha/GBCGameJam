


commandFormatString = "VM_REPLACE_TILE_XY {0}, {1}, ___bank_bg_terminal_tileset_tileset, _bg_terminal_tileset_tileset, {2}\n"
waitString = "VM_INVOKE b_wait_frames, _wait_frames, 0, VAR_TEXT_WAIT\n"

characterVars = {
    " " : "VAR_TEXT_SPACE",

    "1" : "VAR_TEXT_1",
    "2" : "VAR_TEXT_2",
    "3" : "VAR_TEXT_3",
    "3" : "VAR_TEXT_3",
    "4" : "VAR_TEXT_4",
    "5" : "VAR_TEXT_5",
    "6" : "VAR_TEXT_6",
    "7" : "VAR_TEXT_7",
    "8" : "VAR_TEXT_8",
    "9" : "VAR_TEXT_9",

    "A" : "VAR_TEXT_A",
    "B" : "VAR_TEXT_B",
    "C" : "VAR_TEXT_C",
    "D" : "VAR_TEXT_D",
    "E" : "VAR_TEXT_E",
    "F" : "VAR_TEXT_F",
    "G" : "VAR_TEXT_G",
    "G" : "VAR_TEXT_G",
    "H" : "VAR_TEXT_H",
    "I" : "VAR_TEXT_I",
    "J" : "VAR_TEXT_J",

    "K" : "VAR_TEXT_K",
    "L" : "VAR_TEXT_L",
    "M" : "VAR_TEXT_M",
    "N" : "VAR_TEXT_N",
    "O" : "VAR_TEXT_O",
    "0" : "VAR_TEXT_O",
    "P" : "VAR_TEXT_P",
    "Q" : "VAR_TEXT_Q",
    "R" : "VAR_TEXT_R",

    "S" : "VAR_TEXT_S",
    "T" : "VAR_TEXT_T",
    "U" : "VAR_TEXT_U",
    "V" : "VAR_TEXT_V",
    "W" : "VAR_TEXT_W",
    "X" : "VAR_TEXT_X",
    "Y" : "VAR_TEXT_Y",
    "Z" : "VAR_TEXT_Z",

    "/" : "VAR_TEXT_SLASH",

    ":" : "VAR_TEXT_COLON",

    "(" : "VAR_TEXT_LEFTPAREN",
    ")" : "VAR_TEXT_RIGHTPAREN",
}

output = ""

startx = 3
starty = 3

maxHeight = 11
maxWidth = 13

def generateString(targetString):
    targetString = targetString.upper()
    generated = "; {0}\n".format(targetString);

    index = 0
    for y in range(starty, starty + maxHeight):
        for x in range(startx, startx + maxWidth):
            try:
                character = targetString[index]
                print(character)
                print(characterVars[character])
                print("\n")
                generated += commandFormatString.format(x, y, characterVars[character])
                generated += waitString
                index += 1
            except:
                return generated

    return generated


output += generateString("SYSTEM BOOT  "
                        +"/:LOADING    "
                        +"/:LOADING    "
                        +"/:SUCCESS    "
                        +"FLIGHT LOG 83"
                        +"/////////////"
                        +"REACTOR:   OK"
                        +"CRYO:      OK"
                        +"SEC BOTS:  OK"
                        +" ALL SYSTEMS "
                        +"   ONLINE"
          );


# Output resulting commands to file
f = open('text_gbvm.txt', 'w')
f.write(output)
f.close()
