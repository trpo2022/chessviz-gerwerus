#include <libchessviz/Check.h>

Right CheckPawn(
        int H0, int H1, int V0, int V1, char MoveType, int Figure,
        char Desk[][deskSide]) {
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
    strcpy(right.Error, "");
    return right;
}
