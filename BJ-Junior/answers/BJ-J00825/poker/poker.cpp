#include <bits/stdc++.h>
using namespace std;
bool p[4][13];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, ans = 0;
    char a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (a == 'D')
        {
            if ('2' <= b && b <= '9')
                p[0][b-'0'-1] = 1;
            if (b == 'A')
                p[0][0] = 1;
            if (b == 'T')
                p[0][9] = 1;
            if (b == 'J')
                p[0][10] = 1;
            if (b == 'Q')
                p[0][11] = 1;
            if (b == 'K')
                p[0][12] = 1;
        }
        if (a == 'C')
        {
            if ('2' <= b && b <= '9')
                p[1][b-'0'-1] = 1;
            if (b == 'A')
                p[1][0] = 1;
            if (b == 'T')
                p[1][9] = 1;
            if (b == 'J')
                p[1][10] = 1;
            if (b == 'Q')
                p[1][11] = 1;
            if (b == 'K')
                p[1][12] = 1;
        }
        if (a == 'H')
        {
            if ('2' <= b && b <= '9')
                p[2][b-'0'-1] = 1;
            if (b == 'A')
                p[2][0] = 1;
            if (b == 'T')
                p[2][9] = 1;
            if (b == 'J')
                p[2][10] = 1;
            if (b == 'Q')
                p[2][11] = 1;
            if (b == 'K')
                p[2][12] = 1;
        }
        if (a == 'S')
        {
            if ('2' <= b && b <= '9')
                p[3][b-'0'-1] = 1;
            if (b == 'A')
                p[3][0] = 1;
            if (b == 'T')
                p[3][9] = 1;
            if (b == 'J')
                p[3][10] = 1;
            if (b == 'Q')
                p[3][11] = 1;
            if (b == 'K')
                p[3][12] = 1;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            if (p[i][j])
                ans++;
        }
    }
    cout << 52-ans;
    return 0;
}
