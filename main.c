#include <stdio.h>
#define deskSide 8

void PrintDesk(char Desk[deskSide][deskSide]);
int main() {
    char Desk[deskSide][deskSide] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                                     {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                     {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                                     {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    PrintDesk(Desk);
    asdasdasdasd
}

void PrintDesk(char Desk[deskSide][deskSide]) {
    int i;
    for (i = 0; i < deskSide; i++) {
        printf("%d", deskSide - i);
        int j;
        for (j = 0; j < deskSide; j++) {
            printf(" %c", Desk[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h");
}
