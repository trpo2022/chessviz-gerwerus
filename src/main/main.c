#include <libchessviz/Call.h>
#include <libchessviz/Get.h>
#include <libchessviz/MathExtend.h>
#include <libchessviz/PrintDesk.h>
#include <libchessviz/StrExtend.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char Desk[deskSide][deskSide]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    int i = 0, run = 1;
    char WhiteCall[CallSize], BlackCall[CallSize], WhiteFigure, BlackFigure;
    Move WhiteMove, BlackMove;
    Right WhiteRight, BlackRight;

    while (run == 1) {
        i++;
        PrintDesk(Desk);
        printf("\n%d. ", i);

        scanf("%s %s", WhiteCall, BlackCall);

        WhiteFigure = GetFigure(WhiteCall, WHITE);
        BlackFigure = GetFigure(BlackCall, BLACK);
        if (WhiteFigure == '1' || BlackFigure == '1') {
            printf("-> %s <-\n", "Can't get figure!");
            system("pause");
            return 1;
        }

        WhiteMove = GetMove(WhiteCall);
        BlackMove = GetMove(BlackCall);

        WhiteRight = GetRight(WhiteFigure, WhiteMove, Desk);
        BlackRight = GetRight(BlackFigure, BlackMove, Desk);

        if (WhiteRight.Code == 0)
            MakeCall(WhiteMove, WhiteFigure, Desk);
        else {
            printf("-> %s <-\n", WhiteRight.Error);
            system("pause");
            return 1;
        }
        if (BlackRight.Code == 0)
            MakeCall(BlackMove, BlackFigure, Desk);
        else {
            printf("-> %s <-\n", WhiteRight.Error);
            system("pause");
            return 1;
        };
        printf("____________________\n\n");

        //    	system("cls");
    }
}
