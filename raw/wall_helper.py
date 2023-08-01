
# Draw various things in blocks...

commandFormatString = "VM_REPLACE_TILE_XY {0}, {1}, ___bank_bg_aim_background_tileset_tileset, _bg_aim_background_tileset_tileset, {2}\n"

wall_vars = [
    "VAR_WALL_NONE",
    "VAR_WALL_FRONT",
    "VAR_WALL_DARK",
    "VAR_WALL_SIDE",
    "VAR_WALL_SIDELB", # left bottom
    "VAR_WALL_SIDERB", # right bottom
    "VAR_WALL_SIDELT", # left top
    "VAR_WALL_SIDERT", # right top
    "VAR_CRATE_UL",
    "VAR_CRATE_UR",
    "VAR_CRATE_DL",
    "VAR_CRATE_DR",
]

output = ""

def generateBox(startx, starty, width, height, tile):
    generated = "; box(x{0}, y{1}, w{2}, h{3})\n".format(startx, starty, width, height);
    for y in range(starty, starty + height):
        for x in range(startx, startx + width):
            generated += commandFormatString.format(x, y, wall_vars[tile])

    return generated

def generateCorner(x, y, direction):
    generated = "; corner(x{0}, y{1}, d{2})\n".format(x, y, direction);

    if(direction == 0): # top left
        generated += commandFormatString.format(x, y, wall_vars[6]) # wall lt
        generated += commandFormatString.format(x+1, y, wall_vars[0]) # wall none

        generated += commandFormatString.format(x, y+1, wall_vars[3]) # wall side
        generated += commandFormatString.format(x+1, y+1, wall_vars[6]) # wall lt
    elif(direction == 1): # top right
        generated += commandFormatString.format(x, y, wall_vars[0]) # wall none
        generated += commandFormatString.format(x+1, y, wall_vars[7]) # wall rt

        generated += commandFormatString.format(x, y+1, wall_vars[7]) # wall rt
        generated += commandFormatString.format(x+1, y+1, wall_vars[3]) # wall side
    elif(direction == 2): # bottom left
        generated += commandFormatString.format(x, y, wall_vars[3]) # wall side
        generated += commandFormatString.format(x+1, y, wall_vars[4]) # wall lb

        generated += commandFormatString.format(x, y+1, wall_vars[4]) # wall lb
        generated += commandFormatString.format(x+1, y+1, wall_vars[0]) # wall none
    elif(direction == 3): # bottom right
        generated += commandFormatString.format(x, y, wall_vars[5]) # wall rb
        generated += commandFormatString.format(x+1, y, wall_vars[3]) # wall side

        generated += commandFormatString.format(x, y+1, wall_vars[0]) # wall none
        generated += commandFormatString.format(x+1, y+1, wall_vars[5]) # wall rb

    return generated

def generateCrate(x, y):
    generated = "; Crate (x{0}, y{1})\n".format(x, y);

    generated += commandFormatString.format(x, y, wall_vars[8])
    generated += commandFormatString.format(x+1, y, wall_vars[9])
    generated += commandFormatString.format(x, y+1, wall_vars[10])
    generated += commandFormatString.format(x+1, y+1, wall_vars[11])

    return generated



output += generateBox(3, 3, 14, 12, 0);


# Output resulting commands to file
f = open('wall_gbvm.txt', 'w')
f.write(output)
f.close()
