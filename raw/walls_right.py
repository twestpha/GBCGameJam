# Version 0, where block 0 is a wall
# output += "; Column 6\n"
# output += generateBox(12, 4, 2, 4, 0)
# output += generateBox(12, 8, 2, 2, 2)
# output += generateBox(12, 10, 2, 4, 0)
#
# output += "; Column 7\n"
# output += generateBox(14, 2, 2, 4, 0)
# output += generateCorner(14, 6, 1)
# output += generateBox(14, 8, 2, 2, 3)
# output += generateCorner(14, 10, 3)
# output += generateBox(14, 12, 2, 4, 0)
#
# output += "; Column 8\n"
# output += generateBox(16, 2, 2, 2, 0)
# output += generateCorner(16, 4, 1)
# output += generateBox(16, 6, 2, 6, 3)
# output += generateCorner(16, 12, 3)
# output += generateBox(16, 14, 2, 2, 0)
#
# output += "; Column 9\n"
# output += generateCorner(18, 2, 1)
# output += generateBox(18, 4, 2, 10, 3)
# output += generateCorner(18, 14, 3)

# Version 1, where block 1 is a wall
# output += "; Column 6\n"
# output += generateBox(12, 4, 2, 2, 0)
# output += generateCorner(12, 6, 1)
# output += generateBox(12, 8, 2, 2, 3)
# output += generateCorner(12, 10, 3)
# output += generateBox(12, 12, 2, 2, 0)
#
# output += "; Column 7\n"
# output += generateBox(14, 2, 2, 2, 0)
# output += generateCorner(14, 4, 1)
# output += generateBox(14, 6, 2, 6, 3)
# output += generateCorner(14, 12, 3)
# output += generateBox(14, 14, 2, 2, 0)
#
# output += "; Column 8\n"
# output += generateCorner(16, 2, 1)
# output += generateBox(16, 4, 2, 10, 3)
# output += generateCorner(16, 14, 3)
#
# output += "; Column 9\n"
# output += generateBox(18, 2, 2, 14, 1)

# Version 2, where block 2 is a wall
# output += "; Column 6\n"
# output += generateBox(12, 4, 2, 2, 0)
# output += generateCorner(12, 6, 1)
# output += generateBox(12, 8, 2, 2, 3)
# output += generateCorner(12, 10, 3)
# output += generateBox(12, 12, 2, 2, 0)
#
# output += "; Header 7\n"
# output += generateBox(14, 2, 6, 2, 0)
#
# output += "; Column 7\n"
# output += generateCorner(14, 4, 1)
# output += generateBox(14, 6, 2, 6, 3)
# output += generateCorner(14, 12, 3)
#
# output += "; Wall 8\n"
# output += generateBox(16, 4, 4, 10, 1)
#
# output += "; Footer 7\n"
# output += generateBox(14, 14, 6, 2, 0)

# Version 3, where block 3 is a wall
# output += "; Column 6\n"
# output += generateBox(12, 4, 2, 2, 0)
# output += generateCorner(12, 6, 1)
# output += generateBox(12, 8, 2, 2, 3)
# output += generateCorner(12, 10, 3)
# output += generateBox(12, 12, 2, 2, 0)
#
# output += "; Header 7\n"
# output += generateBox(14, 2, 6, 4, 0)
#
# output += "; Wall 8\n"
# output += generateBox(14, 6, 6, 6, 1)
#
# output += "; Footer 7\n"
# output += generateBox(14, 12, 6, 4, 0)

# Version 4, where no blocks are walls
# output += "; Column 6\n"
# output += generateBox(12, 4, 2, 2, 0)
# output += generateBox(12, 8, 2, 2, 0)
#
# output += "; Black Void\n"
# output += generateBox(12, 8, 8, 2, 2)
#
# output += "; Header 7\n"
# output += generateBox(14, 2, 6, 6, 0)
#
# output += "; Footer 7\n"
# output += generateBox(14, 10, 6, 6, 0)