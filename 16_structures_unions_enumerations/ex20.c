enum { NORTH, SOUTH, EAST, WEST } direction;

int main(void) {
    int x, y;
    switch(direction) {
        case NORTH:
            y--;
            break;
        case EAST:
            x++;
            break;
        case SOUTH:
            y++;
            break;
        case WEST:
            x--;
            break;
    }
}
