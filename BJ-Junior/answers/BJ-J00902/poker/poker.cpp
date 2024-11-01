#include <iostream>
using namespace std;

bool s[10][20];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char a, b;
        cin >> a >> b;
        if (a == 'C')
        {
            if (b <= '9')
            {
                s[1][b - '0'] = true;
            }
            else if (b == 'J')
            {
                s[1][11] = true;
            }
            else if (b == 'Q')
            {
                s[1][12] = true;
            }
            else if (b == 'K')
            {
                s[1][13] = true;
            }
            else if (b == 'T')
            {
                s[1][10] = true;
            }
            else
            {
                s[1][1] = true;
            }
        }
        else if (a == 'D')
        {
            if (b <= '9')
            {
                s[2][b - '0'] = true;
            }
            else if (b == 'J')
            {
                s[2][11] = true;
            }
            else if (b == 'Q')
            {
                s[2][12] = true;
            }
            else if (b == 'K')
            {
                s[2][13] = true;
            }
            else if (b == 'T')
            {
                s[2][10] = true;
            }
            else
            {
                s[2][1] = true;
            }
        }
        else if (a == 'H')
        {
            if (b <= '9')
            {
                s[3][b - '0'] = true;
            }
            else if (b == 'J')
            {
                s[3][11] = true;
            }
            else if (b == 'Q')
            {
                s[3][12] = true;
            }
            else if (b == 'K')
            {
                s[3][13] = true;
            }
            else if (b == 'T')
            {
                s[3][10] = true;
            }
            else
            {
                s[3][1] = true;
            }
        }
        else
        {
            if (b <= '9')
            {
                s[4][b - '0'] = true;
            }
            else if (b == 'J')
            {
                s[4][11] = true;
            }
            else if (b == 'Q')
            {
                s[4][12] = true;
            }
            else if (b == 'K')
            {
                s[4][13] = true;
            }
            else if (b == 'T')
            {
                s[4][10] = true;
            }
            else
            {
                s[4][1] = true;
            }
        }
    }
    int cnt = 52;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            if (s[i][j])
            {
                cnt--;
            }
        }
    }
    cout << cnt;
    return 0;
}
