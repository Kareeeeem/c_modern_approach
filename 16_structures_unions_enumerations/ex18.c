typedef enum {
    EMPTY,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
} Piece;

typedef enum {
    BLACK,
    WHITE,
} Color;

typedef struct {
    Piece piece;
    Color color;
} Square;

Square board[8][8] = {
    [0] = {
        { .piece = ROOK },
        { .piece = KNIGHT },
        { .piece = BISHOP },
        { .piece = QUEEN },
        { .piece = KING },
        { .piece = BISHOP },
        { .piece = KNIGHT },
        { .piece = ROOK }
    },
    [1] = {
        { .piece = PAWN },
        { .piece = PAWN },
        { .piece = PAWN },
        { .piece = PAWN },
        { .piece = PAWN },
        { .piece = PAWN },
        { .piece = PAWN },
        { .piece = PAWN }
    },
    [6] = {
        { .color = WHITE, .piece = PAWN },
        { .color = WHITE, .piece = PAWN },
        { .color = WHITE, .piece = PAWN },
        { .color = WHITE, .piece = PAWN },
        { .color = WHITE, .piece = PAWN },
        { .color = WHITE, .piece = PAWN },
        { .color = WHITE, .piece = PAWN },
        { .color = WHITE, .piece = PAWN }
    },
    [7] = {
        { .color = WHITE, .piece = ROOK },
        { .color = WHITE, .piece = KNIGHT },
        { .color = WHITE, .piece = BISHOP },
        { .color = WHITE, .piece = QUEEN },
        { .color = WHITE, .piece = KING },
        { .color = WHITE, .piece = BISHOP },
        { .color = WHITE, .piece = KNIGHT },
        { .color = WHITE, .piece = ROOK }
    },
};
