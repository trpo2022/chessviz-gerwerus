#include <libchessviz/Attack.h>
#include <libchessviz/Collision.h>
#include <libchessviz/MathExtend.h>
#include <libchessviz/StrExtend.h>
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
CTEST(RookCollision, a3_h3) 
{
	const int y1 = 5, x1 = 0, y2 = 5, x2 = 7;
	const int expected = 0;
	const int result = RookCollision(x1, y1, x2, y2 , DefaultDesk);
	ASSERT_EQUAL(expected, result);
}
CTEST(RookCollision, a3_a5) 
{
	const int y1 = 5, x1 = 0, y2 = 3, x2 = 0;
	const int expected = 0;
	const int result = RookCollision(x1, y1, x2, y2 , DefaultDesk);
	ASSERT_EQUAL(expected, result);
}
CTEST(RookCollision, a3_a8) 
{
	const int y1 = 5, x1 = 0, y2 = 0, x2 = 0;
	const int expected = -1;
	const int result = RookCollision(x1, y1, x2, y2 , DefaultDesk);
	ASSERT_EQUAL(expected, result);
}
CTEST(BishopCollision, a3_a8) 
{
	const int y1 = 5, x1 = 0, y2 = 0, x2 = 0;
	const int expected = -1;
	const int result = RookCollision(x1, y1, x2, y2 , DefaultDesk);
	ASSERT_EQUAL(expected, result);
}
CTEST(BishopCollision, a3_d6) 
{
	const int y1 = 5, x1 = 0, y2 = 2, x2 = 3;
	const int expected = 0;
	const int result = BishopCollision(x1, y1, x2, y2 , DefaultDesk);
	ASSERT_EQUAL(expected, result);
}
CTEST(BishopCollision, d6_a3) 
{
	const int y2 = 5, x2 = 0, y1 = 2, x1 = 3;
	const int expected = 0;
	const int result = BishopCollision(x1, y1, x2, y2 , DefaultDesk);
	ASSERT_EQUAL(expected, result);
}
CTEST(BishopCollision, a3_e7) 
{
	const int y1 = 5, x1 = 0, y2 = 1, x2 = 4;
	const int expected = -1;
	const int result = BishopCollision(x1, y1, x2, y2 , DefaultDesk);
	ASSERT_EQUAL(expected, result);
}
CTEST(Minimum, 150_12) 
{
	const int a = 150, b = 12;
	const int expected = 12;
	const int result = min(a, b);
	ASSERT_EQUAL(expected, result);
}
CTEST(Maximum, 1500_12122) 
{
	const int a = 1500, b = 12122;
	const int expected = 12122;
	const int result = max(a, b);
	ASSERT_EQUAL(expected, result);
}
CTEST(IsUpper, A) 
{
	const char a = 'A';
	const int expected = 1;
	const int result = IsUpper(a);
	ASSERT_EQUAL(expected, result);
}
CTEST(strfnd, cccabb_a_3) 
{
	char str[6] = "cccabb";
	char a = 'a';
	const int expected = 3;
	const int result = strfnd(str, a);
	ASSERT_EQUAL(expected, result);
}
