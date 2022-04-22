#include <libchessviz/Call.h>
void MakeCall(Move move, char Figure, char Desk[][deskSide]) {
    Desk[move.V0][move.H0] = ' ';
    Desk[move.V1][move.H1] = Figure;
}
