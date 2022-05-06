#include <libchessviz/Collision.h>
#include <libchessviz/StrExtend.h>
#include <math.h>
#include <stdlib.h>
#pragma once

int UnderAttack(int X, int Y, char Desk[][deskSide]);
int* FindFigure(char Figure, char Desk[][deskSide]);
int KingUnderAttack(int Color, char Desk[][deskSide]);
