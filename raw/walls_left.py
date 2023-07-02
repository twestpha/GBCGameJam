# Version 0, where block 0 is wall
# output += "; Column 0\n"
# output += generateCorner(0, 2, 0)
# output += generateBox(0, 4, 2, 10, 3)
# output += generateCorner(0, 14, 2)
#
# output += "; Column 1\n"
# output += generateBox(2, 2, 2, 2, 0)
# output += generateCorner(2, 4, 0)
# output += generateBox(2, 6, 2, 6, 3)
# output += generateCorner(2, 12, 2)
# output += generateBox(2, 14, 2, 2, 0)
#
# output += "; Column 2\n"
# output += generateBox(4, 2, 2, 4, 0)
# output += generateCorner(4, 6, 0)
# output += generateBox(4, 8, 2, 6, 3)
# output += generateCorner(4, 10, 2)
# output += generateBox(4, 12, 2, 4, 0)
#
# output += "; Column 3\n"
# output += generateBox(6, 4, 2, 4, 0)
# output += generateBox(6, 8, 2, 2, 2)
# output += generateBox(6, 10, 2, 4, 0)

# Version 1, where block 1 is wall
# output += "; Column 1\n"
# output += generateBox(0, 2, 2, 14, 1)
#
# output += "; Column 1\n"
# output += generateCorner(2, 2, 0)
# output += generateBox(2, 4, 2, 10, 3)
# output += generateCorner(2, 14, 2)
#
# output += "; Column 2\n"
# output += generateBox(4, 2, 2, 2, 0)
# output += generateCorner(4, 4, 0)
# output += generateBox(4, 6, 2, 6, 3)
# output += generateCorner(4, 12, 2)
# output += generateBox(4, 14, 2, 2, 0)
#
# output += "; Column 3\n"
# output += generateBox(6, 2, 2, 4, 0)
# output += generateCorner(6, 6, 0)
# output += generateBox(6, 8, 2, 6, 3)
# output += generateCorner(6, 10, 2)
# output += generateBox(6, 12, 2, 4, 0)

# Version 2, where block 2 is wall
# output += "; Header and Footer\n"
# output += generateBox(0, 2, 6, 2, 0)
# output += generateBox(0, 14, 6, 2, 0)
#
# output += "; Wall 0\n"
# output += generateBox(0, 4, 4, 10, 1)
#
# output += "; Column 2\n"
# output += generateCorner(4, 4, 0)
# output += generateBox(4, 6, 2, 6, 3)
# output += generateCorner(4, 12, 2)
#
# output += "; Column 3\n"
# output += generateBox(6, 2, 2, 4, 0)
# output += generateCorner(6, 6, 0)
# output += generateBox(6, 8, 2, 6, 3)
# output += generateCorner(6, 10, 2)
# output += generateBox(6, 12, 2, 4, 0)

# Version 3, where block 3 is wall
# output += "; Header and Footer\n"
# output += generateBox(0, 2, 8, 4, 0)
# output += generateBox(0, 12, 8, 4, 0)
#
# output += "; Wall 0\n"
# output += generateBox(0, 6, 6, 6, 1)
#
# output += "; Column 3\n"
# output += generateCorner(6, 6, 0)
# output += generateBox(6, 8, 2, 2, 3)
# output += generateCorner(6, 10, 2)

# Version 4, where no blocks have walls
# output += "; Header\n"
# output += generateBox(0, 2, 6, 6, 0)
# output += generateBox(6, 4, 2, 4, 0)
#
# output += "; Black Void\n"
# output += generateBox(0, 8, 8, 2, 1)
#
# output += "; Footer\n"
# output += generateBox(0, 10, 6, 6, 0)
# output += generateBox(6, 10, 2, 4, 0)