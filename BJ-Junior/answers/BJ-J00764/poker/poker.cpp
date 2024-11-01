#include <bits/stdc++.h>
using namespace std;

bool a[10][20];

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
        char hua = s[0], dian = s[1];
        if (hua == 'D')
        {
            if (dian == 'A')
            {
                a[1][1] = true;
            }
            else if (dian == 'T')
            {
                a[1][10] = true;
            }
            else if (dian == 'J')
            {
                a[1][11] = true;
            }
            else if (dian == 'Q')
            {
                a[1][12] = true;
            }
            else if (dian == 'K')
            {
                a[1][13] = true;
            }
            else
            {
                int x = dian - '0';
                a[1][x] = true;
            }
        }
        if (hua == 'C')
        {
            if (dian == 'A')
            {
                a[2][1] = true;
            }
            else if (dian == 'T')
            {
                a[2][10] = true;
            }
            else if (dian == 'J')
            {
                a[2][11] = true;
            }
            else if (dian == 'Q')
            {
                a[2][12] = true;
            }
            else if (dian == 'K')
            {
                a[2][13] = true;
            }
            else
            {
                int x = dian - '0';
                a[2][x] = true;
            }
        }
        if (hua == 'H')
        {
            if (dian == 'A')
            {
                a[3][1] = true;
            }
            else if (dian == 'T')
            {
                a[3][10] = true;
            }
            else if (dian == 'J')
            {
                a[3][11] = true;
            }
            else if (dian == 'Q')
            {
                a[3][12] = true;
            }
            else if (dian == 'K')
            {
                a[3][13] = true;
            }
            else
            {
                int x = dian - '0';
                a[3][x] = true;
            }
        }
        if (hua == 'S')
        {
            if (dian == 'A')
            {
                a[4][1] = true;
            }
            else if (dian == 'T')
            {
                a[4][10] = true;
            }
            else if (dian == 'J')
            {
                a[4][11] = true;
            }
            else if (dian == 'Q')
            {
                a[4][12] = true;
            }
            else if (dian == 'K')
            {
                a[4][13] = true;
            }
            else
            {
                int x = dian - '0';
                a[4][x] = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            if (!a[i][j])
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
