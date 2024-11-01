#include <iostream>
#include <string>
using namespace std;

bool have[10][20];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (s[0] == 'D')
        {
            if (s[1] >= '0' && s[1] <= '9')
            {
                have[1][s[1] - '0'] = true;
            }
            if (s[1] == 'A')
            {
                have[1][1] = true;
            }
            if (s[1] == 'T')
            {
                have[1][10] = true;
            }
            if (s[1] == 'J')
            {
                have[1][11] = true;
            }
            if (s[1] == 'Q')
            {
                have[1][12] = true;
            }
            if (s[1] == 'K')
            {
                have[1][13] = true;
            }
        }
        if (s[0] == 'C')
        {
            if (s[1] >= '0' && s[1] <= '9')
            {
                have[2][s[1] - '0'] = true;
            }
            if (s[1] == 'A')
            {
                have[2][1] = true;
            }
            if (s[1] == 'T')
            {
                have[2][10] = true;
            }
            if (s[1] == 'J')
            {
                have[2][11] = true;
            }
            if (s[1] == 'Q')
            {
                have[2][12] = true;
            }
            if (s[1] == 'K')
            {
                have[2][13] = true;
            }
        }
        if (s[0] == 'H')
        {
            if (s[1] >= '0' && s[1] <= '9')
            {
                have[3][s[1] - '0'] = true;
            }
            if (s[1] == 'A')
            {
                have[3][1] = true;
            }
            if (s[1] == 'T')
            {
                have[3][10] = true;
            }
            if (s[1] == 'J')
            {
                have[3][11] = true;
            }
            if (s[1] == 'Q')
            {
                have[3][12] = true;
            }
            if (s[1] == 'K')
            {
                have[3][13] = true;
            }
        }
        if (s[0] == 'S')
        {
            if (s[1] >= '0' && s[1] <= '9')
            {
                have[4][s[1] - '0'] = true;
            }

            if (s[1] == 'A')
            {
                have[4][1] = true;
            }
            if (s[1] == 'T')
            {
                have[4][10] = true;
            }
            if (s[1] == 'J')
            {
                have[4][11] = true;
            }
            if (s[1] == 'Q')
            {
                have[4][12] = true;
            }
            if (s[1] == 'K')
            {
                have[4][13] = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            if (!have[i][j])
            {
                cnt++;
            }
        }
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
