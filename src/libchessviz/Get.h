#include <ctype.h>
#include <libchessviz/Check.h>
#include <libchessviz/StrExtend.h>
#include <string.h>
#define CallSize 10
#define WHITE 0
#define BLACK 1

#pragma once

typedef struct Move {
    int H0;
    int V0;
    int H1;
    int V1;
    char MoveType;
} Move;

char GetFigure(char Call[], int Color);
Move GetMove(char Call[]);
Right GetRight(char Figure, Move move, char Desk[][deskSide]);
