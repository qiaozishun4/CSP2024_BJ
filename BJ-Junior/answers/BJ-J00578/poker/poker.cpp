#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, d, cnt = 0, knum = 0, xnum = 0;
        cin >> x >> y >> d;
        vector<vector<char>> a(n + 2, vector<char>(m + 2, '0'));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cin >> a[i][j];
                if (a[i][j] == 'x')
                {
                    xnum++;
                }
            }
        }
        if (n == 1 && xnum == 0)
        {
            cout << k - y << '\n';
        }
        else
        {
            int i = x, j = y;
            while (a[i][j] == '.' && knum <= k && i >= 1 && i <= n && j >= 1 && j <= m)
            {
                if (d == 0 && a[i][j + 1] != 'x' && knum <= k)
                {
                    knum++;
                    if (knum > k) break;
                    char t = a[i][j + 1];
                    if (t == '0')
                    {
                        d = 1;
                    }
                    cnt++;
                    j++;
                    if (t == '0')
                    {
                        cnt--;
                        j--;
                    }
                }
                else if (d == 0 && a[i][j + 1] == 'x' && knum <= k)
                {
                    d = 1;
                    knum++;
                    if (knum > k) break;
                }
                else if (d == 1 && a[i + 1][j] != 'x' && knum <= k)
                {
                    knum++;
                    if (knum > k) break;
                    char t = a[i + 1][j];
                    if (t == '0')
                    {
                        d = 2;
                    }
                    cnt++;
                    i++;
                    if (t == '0')
                    {
                        cnt--;
                        i--;
                    }
                }
                else if (d == 1 && a[i + 1][j] == 'x' && knum <= k)
                {
                    d = 2;
                    knum++;
                    if (knum > k) break;
                }
                else if (d == 2 && a[i][j - 1] != 'x' && knum <= k)
                {
                    knum++;
                    if (knum > k) break;
                    char t = a[i][j - 1];
                    if (t == '0')
                    {
                        d = 3;
                    }
                    cnt++;
                    j--;
                    if (t == '0')
                    {
                        cnt--;
                        j++;
                    }
                }
                else if (d == 2 && a[i][j - 1] == 'x' && knum <= k)
                {
                    d = 3;
                    knum++;
                    if (knum > k) break;
                }
                else if (d == 3 && a[i - 1][j] != 'x' && knum <= k)
                {
                    knum++;
                    if (knum > k) break;
                    char t = a[i - 1][j];
                    if (t == '0')
                    {
                        d = 0;
                    }
                    cnt++;
                    i--;
                    if (t == '0')
                    {
                        cnt--;
                        i++;
                    }
                }
                else if (d == 3 && a[i - 1][j] == 'x' && knum <= k)
                {
                    d = 0;
                    knum++;
                    if (knum > k) break;
                }
            }
            cout << cnt << '\n';
        }
    }
    return 0;
}
