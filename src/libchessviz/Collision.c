#include <libchessviz/Collision.h>

int RookCollision(int H0, int V0, int H1, int V1, char Desk[][deskSide])
{
    if (V0 == V1) {
        if (H0 > H1) {
            int x;
            for (x = H0; x > H1; x--)
                if (Desk[V0][x] != ' ' && x != H0)
                    return -1;
        } else {
            int x;
            for (x = H0; x < H1; x++)
                if (Desk[V0][x] != ' ' && x != H0)
                    return -1;
        }
    } else if (H0 == H1) {
        if (V0 > V1) {
            int y;
            for (y = V0; y > V1; y--)
                if (Desk[y][H0] != ' ' && y != V0)
                    return -1;
        } else {
            int y;
            for (y = V0; y < V1; y++)
                if (Desk[y][H0] != ' ' && y != V0)
                    return -1;
        }
    } else
        return -1;
    return 0;
}
int BishopCollision(int H0, int V0, int H1, int V1, char Desk[][deskSide])
{
    if (H0 < H1 && V0 < V1) {
        int x = H0, y = V0;
        while (x < H1 && y < V1) {
            x++;
            y++;
            if (Desk[y][x] != ' ')
                return -1;
        }
    }
    if (H0 > H1 && V0 < V1) {
        int x = H0, y = V0;
        while (x > H1 && y < V1) {
            x--;
            y++;
            if (Desk[y][x] != ' ')
                return -1;
        }
    }
    if (H0 < H1 && V0 > V1) {
        int x = H0, y = V0;
        while (x < H1 && y > V1) {
            x++;
            y--;
            if (Desk[y][x] != ' ')
                return -1;
        }
    }
    if (H0 > H1 && V0 > V1) {
        int x = H0, y = V0;
        while (x > H1 && y > V1) {
            x--;
            y--;
            if (Desk[y][x] != ' ')
                return -1;
        }
    }

    return 0;
}
