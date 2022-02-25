#include "stdio.h"

#define deskSide 8
char Desk[deskSide][deskSide] = {
	{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
	{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
	{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
void PrintDesk(char Desk[8][8]);

int main()
{
	PrintDesk(Desk);
}

void PrintDesk(char Desk[8][8])
{
	int i;
	for(i = 0; i < deskSide; i++)
	{
		printf("%d", 8 - i);
		int j;
		for (j = 0; j < deskSide; j++)
		{
			printf(" %c", Desk[i][j]);
		}
		printf("\n");
	}
	printf("  a b c d e f g h");
}

