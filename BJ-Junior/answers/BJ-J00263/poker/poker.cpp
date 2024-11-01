#include<bits/stdc++.h>

using namespace std;

int h[5][15];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans = 0;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s[0] == 'D')
        {
            if (s[1] <= '9' && s[1] >= '2')
                h[1][s[1]-'0']++;
            else if (s[1] == 'T')
                h[1][10]++;
            else if (s[1] == 'A')
                h[1][1]++;
            else
                h[1][s[1]-'J'+11]++;
        }
        else if (s[0] == 'C')
        {
            if (s[1] <= '9' && s[1] >= '2')
                h[2][s[1]-'0']++;
            else if (s[1] == 'T')
                h[2][10]++;
            else if (s[1] == 'A')
                h[2][1]++;
            else
                h[2][s[1]-'J'+11]++;
        }
        if (s[0] == 'H')
        {
            if (s[1] <= '9' && s[1] >= '2')
                h[3][s[1]-'0']++;
            else if (s[1] == 'T')
                h[3][10]++;
            else if (s[1] == 'A')
                h[3][1]++;
            else
                h[3][s[1]-'J'+11]++;
        }
        if (s[0] == 'S')
        {
            if (s[1] <= '9' && s[1] >= '2')
                h[4][s[1]-'0']++;
            else if (s[1] == 'T')
                h[4][10]++;
            else if (s[1] == 'A')
                h[4][1]++;
            else
                h[4][s[1]-'J'+11]++;
        }
    }
    for (int i = 1;i < 5;i++)
    {
        for (int j = 1;j <= 13;j++)
        {
            if (!h[i][j])
                ans++;
        }
    }
    cout << ans;
    return 0;
}
