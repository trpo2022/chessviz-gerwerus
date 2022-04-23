#include <libchessviz/Get.h>

char GetFigure(char Call[], int Color)
{
    char Figure = '1', Alp[CallSize] = "abcdefgh";
    // strcpy(&Figure, Call);
    memcpy(&Figure, Call, sizeof(char));
    // Figure = Call[0];
    if (Figure == tolower(Figure) && strfnd(Alp, Figure) != -1) {
        Figure = 'P';
    }

    if (strfnd("KQRBNP", Figure) == -1)
        return '1';
    if (Color == 1) {
        Figure = tolower(Figure);
    }
    return Figure;
}
Move GetMove(char Call[])
{
    Move move;
    int H0, V0, H1, V1;
    char MoveType, Alp[CallSize] = "abcdefgh", Num[CallSize] = "12345678";
    H0 = strfnd(Alp, Call[0]) + strfnd(Alp, Call[1]) + 1;
    H1 = strfnd(Alp, Call[3]) + strfnd(Alp, Call[4]) + 1;
    V0 = strfnd(Num, Call[1]) + strfnd(Num, Call[2]) + 1;
    V1 = strfnd(Num, Call[4]) + strfnd(Num, Call[5]) + 1;
    V0 = deskSide - V0 - 1;
    V1 = deskSide - V1 - 1;

    if (strfnd(Call, '-') + strfnd(Call, 'x') + 1 == -1)
        MoveType = '1';
    else
        MoveType = Call[strfnd(Call, '-') + strfnd(Call, 'x') + 1];
    move.H0 = H0;
    move.H1 = H1;
    move.V0 = V0;
    move.V1 = V1;
    move.MoveType = MoveType;
    return move;
}

Right GetRight(char Figure, Move move, char Desk[][deskSide])
{
    int H0, H1, V0, V1;
    char MoveType;
    H0 = move.H0;
    H1 = move.H1;
    V0 = move.V0;
    V1 = move.V1;
    MoveType = move.MoveType;
    Right right;

    if (H0 < 0 || H1 < 0 || V0 < 0 || V1 < 0) {
        right.Code = 1;
        strcpy(right.Error, "Can't get coordinats");
        return right;
    }

    if (Desk[V0][H0] != Figure) {
        right.Code = 1;
        strcpy(right.Error, "Different figure");
        return right;
    }

    if (V0 == V1 && H0 == H1) {
        right.Code = 1;
        strcpy(right.Error, "You don't make a move");
        return right;
    };

    if (Figure == 'P' || Figure == 'p') {
        right = CheckPawn(H0, H1, V0, V1, MoveType, Figure, Desk);
        return right;
    }
    else if (Figure == 'K' || Figure == 'k') {
        right = CheckKing(H0, H1, V0, V1, MoveType, Figure, Desk);
        return right;
    }
    else if (Figure == 'N' || Figure == 'n') {
        right = CheckKnight(H0, H1, V0, V1, MoveType, Figure, Desk);
        return right;
    }
    else if (Figure == 'Q' || Figure == 'q') {
        right = CheckQueen(H0, H1, V0, V1, MoveType, Figure, Desk);
        return right;
    }
    else if (Figure == 'R' || Figure == 'r') {
        right = CheckRook(H0, H1, V0, V1, MoveType, Figure, Desk);
        return right;
    }
    else if (Figure == 'B' || Figure == 'b') {
        right = CheckBishop(H0, H1, V0, V1, MoveType, Figure, Desk);
        return right;
    }
    right.Code = 0;
    strcpy(right.Error, "---");
    return right;
}
