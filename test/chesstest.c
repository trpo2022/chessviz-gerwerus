#include <libchessviz/Attack.h>
#include <../thirdparty/ctest.h>

char DefaultDesk[deskSide][deskSide]
			= {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

CTEST(UnderAttack, a6) 
{
	const int x = 2;
	const int y = 0;
	const int expected = -1;
	const int result = UnderAttack(x, y, DefaultDesk);
	ASSERT_EQUAL(expected, result);
}
CTEST(UnderAttack, a5) 
{
	const int x = 3;
	const int y = 0;
	const int expected = 0;
	const int result = UnderAttack(x, y, DefaultDesk);
	ASSERT_EQUAL(expected, result);
}
CTEST(UnderAttack, a3) 
{
	const int x = 5;
	const int y = 0;
	const int expected = 1;
	const int result = UnderAttack(x, y, DefaultDesk);
	ASSERT_EQUAL(expected, result);
}
CTEST(FindFigure, WhiteKing) 
{
	int *result = (int*)malloc(sizeof(int) * 2);
	int *expected = (int*)malloc(sizeof(int) * 2);
	const char WhiteKing = 'K'; 
	expected[0] = 7;
	expected[1] = 4;
	result = FindFigure(WhiteKing, DefaultDesk);
	ASSERT_EQUAL(expected[0], result[0]);
	ASSERT_EQUAL(expected[1], result[1]);
	free(result);
	free(expected);
}
CTEST(FindFigure, BlackKing) 
{
	int *result = (int*)malloc(sizeof(int) * 2);
	int *expected = (int*)malloc(sizeof(int) * 2);
	const char WhiteKing = 'k'; 
	expected[0] = 0;
	expected[1] = 4;
	result = FindFigure(WhiteKing, DefaultDesk);
	ASSERT_EQUAL(expected[0], result[0]);
	ASSERT_EQUAL(expected[1], result[1]);
	free(result);
	free(expected);
}
CTEST(KingUnderAttack, White) 
{
	const int white = 1;
	const int expected = 0;
	const int result = KingUnderAttack(white, DefaultDesk);
	ASSERT_EQUAL(expected, result);
}
