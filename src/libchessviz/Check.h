#include <libchessviz/StrExtend.h>

#define deskSide 8
#pragma once
typedef struct Right {
    int Code;
    char Error[100];
} Right;

Right CheckPawn(
        int H0, int H1, int V0, int V1, char MoveType, int Figure,
        char Desk[][deskSide]);
