#include <bits/stdc++.h>
using namespace std;
int n;
char a, b;
bool appear[10][20];
int cnt = 0;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%d", &n);
    while (n--)
    {
        scanf("\n%c%c", &a, &b);
        int tmp1, tmp2;
        switch (a)
        {
            case 'D':
                tmp1 = 1;
                break;
            case 'C':
                tmp1 = 2;
                break;
            case 'H':
                tmp1 = 3;
                break;
            case 'S':
                tmp1 = 4;
                break;
        }
        switch (b)
        {
            case 'A':
                tmp2 = 1;
                break;
            case 'T':
                tmp2 = 10;
                break;
            case 'J':
                tmp2 = 11;
                break;
            case 'Q':
                tmp2 = 12;
                break;
            case 'K':
                tmp2 = 13;
                break;
            default:
                tmp2 = b - '0';
                break;
        }
        appear[tmp1][tmp2] = 1;
    }
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 13; j++)
            if (!appear[i][j])
                cnt++;
    printf("%d\n", cnt);
    return 0;
}
