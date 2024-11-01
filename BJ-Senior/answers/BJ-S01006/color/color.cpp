#include <bits/stdc++.h>
using namespace std;
int n, a[200010], s[200010], num[2][1000010];
int main ()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        memset(num, 0, sizeof(num));
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int j = 1; j <= n - 1; j++)
        {
            for (int i = j + 1; i <= n; i++)
            {
                if (a[i] == a[i - j])
                {
                    bool flag = 1;
                    int t = 1;
                    for (int k = i - j + 1; k < i - 1; k++)
                    {
                        t = (s[k] != 0 ? s[k] : t);
                        if (s[k] != 0 && s[k + 1] != 0 && s[k] != s[k + 1]) flag = 0;
                    }
                    t = (s[i - 1] != 0 ? s[i - 1] : t);
                    if (flag)
                    {
                        s[i] = s[i - j] = (t == 1 ? 2 : 1);
                        for (int k = i - j + 1; k < i; k++) s[k] = t;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == 1) num[0][a[i]]++;
            else num[1][a[i]]++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (num[0][a[i]]) ans += (num[0][a[i]] - 1) * a[i];
            if (num[1][a[i]]) ans += (num[1][a[i]] - 1) * a[i];
            num[0][a[i]] = num[1][a[i]] = 0;
        }
        cout << ans << endl;
    }
    return 0;
}
