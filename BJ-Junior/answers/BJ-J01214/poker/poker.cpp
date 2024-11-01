#include <bits/stdc++.h>
using namespace std;
int n, ans;
int a[4][100], cnt[4];
string s;
int main ()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        int x;
        if (s[1] == 'A') x = 1;
        else if (s[1] == 'T') x = 10;
        else if (s[1] == 'J') x = 11;
        else if (s[1] == 'Q') x = 12;
        else if (s[1] == 'K') x = 13;
        else x = s[1] - '0';
        if (s[0] == 'D') a[0][++cnt[0]] = x;
        else if (s[0] == 'C') a[1][++cnt[1]] = x;
        else if (s[0] == 'H') a[2][++cnt[2]] = x;
        else a[3][++cnt[3]] = x;
    }
    for (int i = 0; i < 4; i++)
    {
        if (cnt[i] <= 1) continue;
        sort(a[i] + 1, a[i] + cnt[i] + 1);
    }
    for (int i = 0; i < 4; i++)
    {
        int j = 1;
        for (int k = 1; k <= cnt[i]; k++)
        {
            if (j > a[i][k]) continue;
            ans += a[i][k] - j;
            j = a[i][k] + 1;
        }
        ans += 13 - j + 1;
    }
    cout << ans << endl;
    return 0;
}
