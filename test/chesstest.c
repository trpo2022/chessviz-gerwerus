#include <../thirdparty/ctest.h>
#include <libchessviz/Attack.h>
#include <libchessviz/Collision.h>
#include <libchessviz/Get.h>
#include <libchessviz/MathExtend.h>
#include <libchessviz/StrExtend.h>

char DefaultDesk[deskSide][deskSide]
        = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
           {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
           {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

CTEST(UnderAttack, a6) {
    const int x = 2;
    const int y = 0;
    const int expected = -1;
    const int result = UnderAttack(x, y, DefaultDesk);
    ASSERT_EQUAL(expected, result);
}
CTEST(UnderAttack, a5) {
    const int x = 3;
    const int y = 0;
    const int expected = 0;
    const int result = UnderAttack(x, y, DefaultDesk);
    ASSERT_EQUAL(expected, result);
}
CTEST(UnderAttack, a3) {
    const int x = 5;
    const int y = 0;
    const int expected = 1;
    const int result = UnderAttack(x, y, DefaultDesk);
    ASSERT_EQUAL(expected, result);
}
CTEST(FindFigure, WhiteKing) {
    int* result = (int*)malloc(sizeof(int) * 2);
    int* expected = (int*)malloc(sizeof(int) * 2);
    const char WhiteKing = 'K';
    expected[0] = 7;
    expected[1] = 4;
    result = FindFigure(WhiteKing, DefaultDesk);
    ASSERT_EQUAL(expected[0], result[0]);
    ASSERT_EQUAL(expected[1], result[1]);
    free(result);
    free(expected);
}
CTEST(FindFigure, BlackKing) {
    int* result = (int*)malloc(sizeof(int) * 2);
    int* expected = (int*)malloc(sizeof(int) * 2);
    const char WhiteKing = 'k';
    expected[0] = 0;
    expected[1] = 4;
    result = FindFigure(WhiteKing, DefaultDesk);
    ASSERT_EQUAL(expected[0], result[0]);
    ASSERT_EQUAL(expected[1], result[1]);
    free(result);
    free(expected);
}
CTEST(KingUnderAttack, White) {
    const int white = 1;
    const int expected = 0;
    const int result = KingUnderAttack(white, DefaultDesk);
    ASSERT_EQUAL(expected, result);
}
CTEST(RookCollision, a3_h3) {
    const int y1 = 5, x1 = 0, y2 = 5, x2 = 7;
    const int expected = 0;
    const int result = RookCollision(x1, y1, x2, y2, DefaultDesk);
    ASSERT_EQUAL(expected, result);
}
CTEST(RookCollision, a3_a5) {
    const int y1 = 5, x1 = 0, y2 = 3, x2 = 0;
    const int expected = 0;
    const int result = RookCollision(x1, y1, x2, y2, DefaultDesk);
    ASSERT_EQUAL(expected, result);
}
CTEST(RookCollision, a3_a8) {
    const int y1 = 5, x1 = 0, y2 = 0, x2 = 0;
    const int expected = -1;
    const int result = RookCollision(x1, y1, x2, y2, DefaultDesk);
    ASSERT_EQUAL(expected, result);
}
CTEST(BishopCollision, a3_a8) {
    const int y1 = 5, x1 = 0, y2 = 0, x2 = 0;
    const int expected = -1;
    const int result = RookCollision(x1, y1, x2, y2, DefaultDesk);
    ASSERT_EQUAL(expected, result);
}
CTEST(BishopCollision, a3_d6) {
    const int y1 = 5, x1 = 0, y2 = 2, x2 = 3;
    const int expected = 0;
    const int result = BishopCollision(x1, y1, x2, y2, DefaultDesk);
    ASSERT_EQUAL(expected, result);
}
CTEST(BishopCollision, d6_a3) {
    const int y2 = 5, x2 = 0, y1 = 2, x1 = 3;
    const int expected = 0;
    const int result = BishopCollision(x1, y1, x2, y2, DefaultDesk);
    ASSERT_EQUAL(expected, result);
}
CTEST(BishopCollision, a3_e7) {
    const int y1 = 5, x1 = 0, y2 = 1, x2 = 4;
    const int expected = -1;
    const int result = BishopCollision(x1, y1, x2, y2, DefaultDesk);
    ASSERT_EQUAL(expected, result);
}
CTEST(Minimum, 150_12) {
    const int a = 150, b = 12;
    const int expected = 12;
    const int result = min(a, b);
    ASSERT_EQUAL(expected, result);
}
CTEST(Maximum, 1500_12122) {
    const int a = 1500, b = 12122;
    const int expected = 12122;
    const int result = max(a, b);
    ASSERT_EQUAL(expected, result);
}
CTEST(IsUpper, A) {
    const char a = 'A';
    const int expected = 1;
    const int result = IsUpper(a);
    ASSERT_EQUAL(expected, result);
}
CTEST(strfnd, cccabb_a_3) {
    char str[6] = "cccabb";
    char a = 'a';
    const int expected = 3;
    const int result = strfnd(str, a);
    ASSERT_EQUAL(expected, result);
}
CTEST(GetFigure, e2_e4_P) {
    int Color = 0;
    char Call[10] = "e2-e4";
    char expected = 'P';
    char result = GetFigure(Call, Color);
    ASSERT_EQUAL(expected, result);
}
CTEST(GetFigure, Kd2_f4_k) {
    int Color = 1;
    char Call[10] = "Kd2-f4";
    char expected = 'k';
    char result = GetFigure(Call, Color);
    ASSERT_EQUAL(expected, result);
}
CTEST(GetFigure, Rd2_f4_R) {
    int Color = 0;
    char Call[10] = "Rd2-f4";
    char expected = 'R';
    char result = GetFigure(Call, Color);
    ASSERT_EQUAL(expected, result);
}
CTEST(GetFigure, Rd2_f4_r) {
    int Color = 1;
    char Call[10] = "Rd2-f4";
    char expected = 'r';
    char result = GetFigure(Call, Color);
    ASSERT_EQUAL(expected, result);
}
CTEST(GetMove, e2_e4) {
    char Call[10] = "e2-e4";
    Move expected;
    expected.H0 = 4;
    expected.H1 = 4;
    expected.V0 = 6;
    expected.V1 = 4;
    expected.MoveType = '-';
    Move result = GetMove(Call);
    ASSERT_EQUAL(expected.H0, result.H0);
    ASSERT_EQUAL(expected.H1, result.H1);
    ASSERT_EQUAL(expected.V0, result.V0);
    ASSERT_EQUAL(expected.V1, result.V1);
    ASSERT_EQUAL(expected.MoveType, result.MoveType);
}
CTEST(GetMove, d2xd3) {
    char Call[10] = "d2xd3";
    Move expected;
    expected.H0 = 3;
    expected.H1 = 3;
    expected.V0 = 6;
    expected.V1 = 5;
    expected.MoveType = 'x';
    Move result = GetMove(Call);
    ASSERT_EQUAL(expected.H0, result.H0);
    ASSERT_EQUAL(expected.H1, result.H1);
    ASSERT_EQUAL(expected.V0, result.V0);
    ASSERT_EQUAL(expected.V1, result.V1);
    ASSERT_EQUAL(expected.MoveType, result.MoveType);
}
