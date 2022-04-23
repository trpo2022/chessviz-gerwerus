#include <libchessviz/Check.h>

Right CheckPawn(
        int H0,
        int H1,
        int V0,
        int V1,
        char MoveType,
        int Figure,
        char Desk[][deskSide])
{
    int Color = IsUpper(Figure);
    Right right;
    if (H0 == H1) {
        if (Desk[V1][H1] != ' ') {
            right.Code = 1;
            strcpy(right.Error, "Pawn can't move like that");
            return right;
        };
        if ((V0 - V1) * Color > 2 || (V0 - V1) * Color < 0) {
            right.Code = 1;
            strcpy(right.Error, "Pawn can't move like that");
            return right;
        };
        if ((V0 - V1) * Color == 2
            && (V0 != (deskSide - 1 - 1 * Color) % (deskSide - 1)
                || Desk[V0 - Color][H0] != ' ')) {
            right.Code = 1;
            strcpy(right.Error, "Pawn can't move like that");
            return right;
        };
        if (MoveType != '-') {
            right.Code = 1;
            strcpy(right.Error, "Wrong move type");
            return right;
        };
    } else {
        if (H1 - H0 != 1 && H0 - H1 != 1) {
            right.Code = 1;
            strcpy(right.Error, "Pawn can't move like that");
            return right;
        };
        if ((V0 - V1) * Color != 1) {
            right.Code = 1;
            strcpy(right.Error, "Pawn can't move like that");
            return right;
        };
        if (Desk[V1][H1] == ' ') {
            right.Code = 1;
            strcpy(right.Error, "Pawn can't move like that");
            return right;
        };
        if (Color == IsUpper(Desk[V1][H1])) {
            right.Code = 1;
            strcpy(right.Error, "Pawn can't move like that");
            return right;
        };
        if (MoveType != 'x') {
            right.Code = 1;
            strcpy(right.Error, "Wrong move type");
            return right;
        };
    }
    right.Code = 0;
    right.Rokirovka = 0;
    strcpy(right.Error, "");
    return right;
}

Right CheckKing(
        int H0,
        int H1,
        int V0,
        int V1,
        char MoveType,
        int Figure,
        char Desk[][deskSide])
{
    int Color = IsUpper(Figure);
    Right right;

    if (abs(V1 - V0) > 1 || abs(H1 - H0) > 1) {
        right.Code = 1;
        strcpy(right.Error, "King can't move like that");
        return right;
    };
    if (abs(V1 - V0) == 0 && abs(H1 - H0) == 0) {
        right.Code = 1;
        strcpy(right.Error, "King can't move like that");
        return right;
    };
    if (Desk[V1][H1] != ' ') {
        if (Color == IsUpper(Desk[V1][H1])) {
            right.Code = 1;
            strcpy(right.Error, "King can't move like that");
            return right;
        } else if (MoveType != 'x') {
            right.Code = 1;
            strcpy(right.Error, "Wrong move type");
            return right;
        }
    }
    right.Code = 0;
    right.Rokirovka = 1;
    strcpy(right.Error, "");
    return right;
}

Right CheckKnight(
        int H0,
        int H1,
        int V0,
        int V1,
        char MoveType,
        int Figure,
        char Desk[][deskSide])
{
    int Color = IsUpper(Figure);
    Right right;

    if (abs(V1 - V0) + abs(H1 - H0) != 3) {
        right.Code = 1;
        strcpy(right.Error, "Knight can't move like that");
        return right;
    }
    if (abs(V1 - V0) == 0 || abs(H1 - H0) == 0) {
        right.Code = 1;
        strcpy(right.Error, "Knight can't move like that");
        return right;
    }

    if (Desk[V1][H1] != ' ') {
        if (Color == IsUpper(Desk[V1][H1])) {
            right.Code = 1;
            strcpy(right.Error, "Knight can't move like that");
            return right;
        } else if (MoveType != 'x') {
            right.Code = 1;
            strcpy(right.Error, "Wrong move type");
            return right;
        }
    }

    right.Code = 0;
    right.Rokirovka = 0;
    strcpy(right.Error, "");
    return right;
}

Right CheckQueen(
        int H0,
        int H1,
        int V0,
        int V1,
        char MoveType,
        int Figure,
        char Desk[][deskSide])
{
    int Color = IsUpper(Figure);
    Right right;

    if (H0 == H1 || V0 == V1) {
        if (RookCollision(H0, V0, H1, V1, Desk) == -1) {
            right.Code = 1;
            strcpy(right.Error, "Queen can't move like that");
            return right;
        }
    } else if (abs(H0 - H1) == abs(V0 - V1)) {
        if (BishopCollision(H0, V0, H1, V1, Desk) == -1) {
            right.Code = 1;
            strcpy(right.Error, "Queen can't move like that");
            return right;
        }
    } else {
        right.Code = 1;
        strcpy(right.Error, "Queen can't move like that");
        return right;
    }

    if (Desk[V1][H1] != ' ') {
        if (Color == IsUpper(Desk[V1][H1])) {
            right.Code = 1;
            strcpy(right.Error, "Queen can't move like that");
            return right;
        } else if (MoveType != 'x') {
            right.Code = 1;
            strcpy(right.Error, "Wrong move type");
            return right;
        }
    }

    right.Code = 0;
    right.Rokirovka = 0;
    strcpy(right.Error, "");
    return right;
}

Right CheckRook(
        int H0,
        int H1,
        int V0,
        int V1,
        char MoveType,
        int Figure,
        char Desk[][deskSide])
{
    int Color = IsUpper(Figure);
    Right right;

    if (H0 == H1 || V0 == V1) {
        if (RookCollision(H0, V0, H1, V1, Desk) == -1) {
            right.Code = 1;
            strcpy(right.Error, "Rook can't move like that");
            return right;
        }
    } else {
        right.Code = 1;
        strcpy(right.Error, "Rook can't move like that");
        return right;
    }

    if (Desk[V1][H1] != ' ') {
        if (Color == IsUpper(Desk[V1][H1])) {
            right.Code = 1;
            strcpy(right.Error, "Rook can't move like that");
            return right;
        } else if (MoveType != 'x') {
            right.Code = 1;
            strcpy(right.Error, "Wrong move type");
            return right;
        }
    }

    right.Code = 0;
    right.Rokirovka = 0;
    strcpy(right.Error, "");
    return right;
}

Right CheckBishop(
        int H0,
        int H1,
        int V0,
        int V1,
        char MoveType,
        int Figure,
        char Desk[][deskSide])
{
    int Color = IsUpper(Figure);
    Right right;

    if (abs(H0 - H1) == abs(V0 - V1)) {
        if (BishopCollision(H0, V0, H1, V1, Desk) == -1) {
            right.Code = 1;
            strcpy(right.Error, "Queen can't move like that");
            return right;
        }
    } else {
        right.Code = 1;
        strcpy(right.Error, "Queen can't move like that");
        return right;
    }

    if (Desk[V1][H1] != ' ') {
        if (Color == IsUpper(Desk[V1][H1])) {
            right.Code = 1;
            strcpy(right.Error, "Queen can't move like that");
            return right;
        } else if (MoveType != 'x') {
            right.Code = 1;
            strcpy(right.Error, "Wrong move type");
            return right;
        }
    }

    right.Code = 0;
    right.Rokirovka = 0;
    strcpy(right.Error, "");
    return right;
}
