#include <bits/stdc++.h>
using namespace std;
int v[140][40];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        if (s[0] == 'D')
        {
            if (s[1] >= '0' && s[1] <= '9')
            {
                v[s[1] - '0'][0] = 1;
            }
            else
            {
                if (s[1] == 'A')
                {
                    v[1][0] = 1;
                }
                if (s[1] == 'T')
                {
                    v[10][0] = 1;
                }
                if (s[1] == 'J')
                {
                    v[11][0] = 1;
                }
                if (s[1] == 'Q')
                {
                    v[12][0] = 1;
                }
                if (s[1] == 'K')
                {
                    v[13][0] = 1;
                }
            }
        }
        if (s[0] == 'C')
        {
            if (s[1] >= '0' && s[1] <= '9')
            {
                v[s[1] - '0'][1] = 1;
            }
            else
            {
                if (s[1] == 'A')
                {
                    v[1][1] = 1;
                }
                if (s[1] == 'T')
                {
                    v[10][1] = 1;
                }
                if (s[1] == 'J')
                {
                    v[11][1] = 1;
                }
                if (s[1] == 'Q')
                {
                    v[12][1] = 1;
                }
                if (s[1] == 'K')
                {
                    v[13][1] = 1;
                }
            }
        }
        if (s[0] == 'H')
        {
            if (s[1] >= '0' && s[1] <= '9')
            {
                v[s[1] - '0'][2] = 1;
            }
            else
            {
                if (s[1] == 'A')
                {
                    v[1][2] = 1;
                }
                if (s[1] == 'T')
                {
                    v[10][2] = 1;
                }
                if (s[1] == 'J')
                {
                    v[11][2] = 1;
                }
                if (s[1] == 'Q')
                {
                    v[12][2] = 1;
                }
                if (s[1] == 'K')
                {
                    v[13][2] = 1;
                }
            }
        }
        if (s[0] == 'S')
        {
            if (s[1] >= '0' && s[1] <= '9')
            {
                v[s[1] - '0'][3] = 1;
            }
            else
            {
                if (s[1] == 'A')
                {
                    v[1][3] = 1;
                }
                if (s[1] == 'T')
                {
                    v[10][3] = 1;
                }
                if (s[1] == 'J')
                {
                    v[11][3] = 1;
                }
                if (s[1] == 'Q')
                {
                    v[12][3] = 1;
                }
                if (s[1] == 'K')
                {
                    v[13][3] = 1;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1;i <= 13;i++)
    {
        for (int j = 0;j <= 3;j++)
        {
            if (v[i][j] == 0)
            {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
