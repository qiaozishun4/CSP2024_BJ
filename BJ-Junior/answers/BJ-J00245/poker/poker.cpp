#include <bits/stdc++.h>
using namespace std;

bool occured[10][20];

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f *= -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n = read();
    int occurence = 0;
    for (int i = 0; i < n; i++) {
        char color = getchar(), point = getchar();
        int x = 0, y = 0;
        if (color == 'D') x = 0;
        else if (color == 'C') x = 1;
        else if (color == 'H') x = 2;
        else if (color == 'S') x = 3;
        if (point == 'A') y = 1;
        else if (point == 'T') y = 10;
        else if (point == 'J') y = 11;
        else if (point == 'Q') y = 12;
        else if (point == 'K') y = 13;
        else y = point - '0';
        if (!occured[x][y]) {
            occured[x][y] = true;
            occurence++;
        }
        getchar();
    }
    printf("%d\n", 52 - occurence);
    return 0;
}