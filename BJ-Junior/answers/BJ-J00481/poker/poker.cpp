#include <bits/stdc++.h>
using namespace std;

bool poker[5][14];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    memset(poker, false, sizeof(poker));
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        if (s[0] == 'D')
        {
            if (s[1] == 'A')
            {
                poker[1][1] = 1;
            }
            if (s[1] == '2')
            {
                poker[1][2] = 1;
            }
            if (s[1] == '3')
            {
                poker[1][3] = 1;
            }
            if (s[1] == '4')
            {
                poker[1][4] = 1;
            }
            if (s[1] == '5')
            {
                poker[1][5] = 1;
            }
            if (s[1] == '6')
            {
                poker[1][6] = 1;
            }
            if (s[1] == '7')
            {
                poker[1][7] = 1;
            }
            if (s[1] == '8')
            {
                poker[1][8] = 1;
            }
            if (s[1] == '9')
            {
                poker[1][9] = 1;
            }
            if (s[1] == 'T')
            {
                poker[1][10] = 1;
            }
            if (s[1] == 'J')
            {
                poker[1][11] = 1;
            }
            if (s[1] == 'Q')
            {
                poker[1][12] = 1;
            }
            if (s[1] == 'K')
            {
                poker[1][13] = 1;
            }
        }
        if (s[0] == 'C')
        {
            if (s[1] == 'A')
            {
                poker[2][1] = 1;
            }
            if (s[1] == '2')
            {
                poker[2][2] = 1;
            }
            if (s[1] == '3')
            {
                poker[2][3] = 1;
            }
            if (s[1] == '4')
            {
                poker[2][4] = 1;
            }
            if (s[1] == '5')
            {
                poker[2][5] = 1;
            }
            if (s[1] == '6')
            {
                poker[2][6] = 1;
            }
            if (s[1] == '7')
            {
                poker[2][7] = 1;
            }
            if (s[1] == '8')
            {
                poker[2][8] = 1;
            }
            if (s[1] == '9')
            {
                poker[2][9] = 1;
            }
            if (s[1] == 'T')
            {
                poker[2][10] = 1;
            }
            if (s[1] == 'J')
            {
                poker[2][11] = 1;
            }
            if (s[1] == 'Q')
            {
                poker[2][12] = 1;
            }
            if (s[1] == 'K')
            {
                poker[2][13] = 1;
            }
        }
        if (s[0] == 'H')
        {
            if (s[1] == 'A')
            {
                poker[3][1] = 1;
            }
            if (s[1] == '2')
            {
                poker[3][2] = 1;
            }
            if (s[1] == '3')
            {
                poker[3][3] = 1;
            }
            if (s[1] == '4')
            {
                poker[3][4] = 1;
            }
            if (s[1] == '5')
            {
                poker[3][5] = 1;
            }
            if (s[1] == '6')
            {
                poker[3][6] = 1;
            }
            if (s[1] == '7')
            {
                poker[3][7] = 1;
            }
            if (s[1] == '8')
            {
                poker[3][8] = 1;
            }
            if (s[1] == '9')
            {
                poker[3][9] = 1;
            }
            if (s[1] == 'T')
            {
                poker[3][10] = 1;
            }
            if (s[1] == 'J')
            {
                poker[3][11] = 1;
            }
            if (s[1] == 'Q')
            {
                poker[3][12] = 1;
            }
            if (s[1] == 'K')
            {
                poker[3][13] = 1;
            }
        }
        if (s[0] == 'S')
        {
            if (s[1] == 'A')
            {
                poker[4][1] = 1;
            }
            if (s[1] == '2')
            {
                poker[4][2] = 1;
            }
            if (s[1] == '3')
            {
                poker[4][3] = 1;
            }
            if (s[1] == '4')
            {
                poker[4][4] = 1;
            }
            if (s[1] == '5')
            {
                poker[4][5] = 1;
            }
            if (s[1] == '6')
            {
                poker[4][6] = 1;
            }
            if (s[1] == '7')
            {
                poker[4][7] = 1;
            }
            if (s[1] == '8')
            {
                poker[4][8] = 1;
            }
            if (s[1] == '9')
            {
                poker[4][9] = 1;
            }
            if (s[1] == 'T')
            {
                poker[4][10] = 1;
            }
            if (s[1] == 'J')
            {
                poker[4][11] = 1;
            }
            if (s[1] == 'Q')
            {
                poker[4][12] = 1;
            }
            if (s[1] == 'K')
            {
                poker[4][13] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= 13; ++j)
        {
            if (poker[i][j] == true) cnt++;
        }
    }
    cout << 52 - cnt;
    return 0;
}