#include <bits/stdc++.h>
using namespace std;

int a[60];

int main()
{
    //freopen("poker.in", "r", stdin);
    //freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    int ans = 52 - n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (s[0] == 'D')
        {
            if (s[1] == 'A')
            {
                a[1]++;
            }
            else if (s[1] == 'T')
            {
                a[10]++;
            }
            else if (s[1] == 'J') a[11]++;
            else if (s[1] == 'Q') a[12]++;
            else if (s[1] == 'K') a[13]++;
            else a[s[1] - '0']++;
        }
        else if (s[0] == 'C')
        {
            if (s[1] == 'A')
            {
                a[14]++;
            }
            else if (s[1] == 'T')
            {
                a[23]++;
            }
            else if (s[1] == 'J') a[24]++;
            else if (s[1] == 'Q') a[25]++;
            else if (s[1] == 'K') a[26]++;
            else a[s[1] - '0' + 13]++;
        }
        else if (s[0] == 'H')
        {
            if (s[1] == 'A')
            {
                a[27]++;
            }
            else if (s[1] == 'T')
            {
                a[36]++;
            }
            else if (s[1] == 'J') a[37]++;
            else if (s[1] == 'Q') a[38]++;
            else if (s[1] == 'K') a[39]++;
            else a[s[1] - '0' + 26]++;
        }
        else if (s[0] == 'C')
        {
            if (s[1] == 'A')
            {
                a[40]++;
            }
            else if (s[1] == 'T')
            {
                a[23]++;
            }
            else if (s[1] == 'J') a[50]++;
            else if (s[1] == 'Q') a[51]++;
            else if (s[1] == 'K') a[52]++;
            else a[s[1] - '0' + 39]++;
        }
    }
    for (int i = 1; i <= 52; i++)
    {
        if (a[i] > 1) ans += a[i] - 1;
    }
    cout << ans << endl;
    return 0;
}
