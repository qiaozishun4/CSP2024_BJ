#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], maxn;
bool vis[N];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    if (maxn <= 2)
    {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 1) cnt1++;
            if (a[i] == 2) cnt2++;
        }
        if (cnt2 >= cnt1) cout << cnt2 << "\n";
        else cout << cnt1 << "\n";
        return 0;
    }
    sort(a+1, a+n+1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            int t = i, id;
            bool flag = true;
            while (true)
            {
                id = -1;
                for (int j = t+1; j <= n; j++)
                {
                    if (!vis[j] && a[j] != a[t])
                    {
                        id = j;
                        break;
                    }
                }
                if (id == -1)
                {
                    ans++;
                    break;
                }
                vis[t] = true;
                t = id;
            }
            vis[t] = true;
        }
    }
    cout << ans << "\n";
    return 0;
}