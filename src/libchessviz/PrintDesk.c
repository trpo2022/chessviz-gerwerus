#include <libchessviz/PrintDesk.h>

void PrintDesk(char Desk[deskSide][deskSide])
{
    int i;
    for (i = 0; i < deskSide; i++)
    {
        printf("%d", deskSide - i);
        int j;
        for (j = 0; j < deskSide; j++)
        {
            printf(" %c", Desk[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h");
}
