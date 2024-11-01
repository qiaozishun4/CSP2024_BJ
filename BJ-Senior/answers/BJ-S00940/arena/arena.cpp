#include <bits/stdc++.h>
using namespace std;
int n, m, T, x[5];
int a[100010], c[100010], t[100010];
string g[100010];
long long twice[40] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296,8589934592};
int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> c[i];
    int cur = 0;
    while (n > twice[cur])
    {
        ++cur;
    }
    for (int i = 1; i <= cur; ++i)
    {
        cin >> g[i];
        g[i] = '*' + g[i];
    }
    cin >> T;
    while (T--)
    {
        long long ans = 0;
        for (int i = 0; i <= 3; ++i) cin >> x[i];
        for (int i = 1; i <= n; ++i) t[i] = a[i] ^ x[i % 4];
        for (int i = 1; i <= m; ++i)
        {
            int k = 0;
            while (twice[k] < c[i]) ++k;
            queue<int> winid;
            while (!winid.empty()) winid.pop();
            for (int round = 1; round <= k; ++round)
            {
                for (int id = 1; id <= c[i] / 2; ++id)
                {
                    if (g[round][id] == '1')
                    {
                        if (t[id * 2] >= round)
                        {
                            if (!winid.empty()) winid.pop();
                            if (!winid.empty()) winid.pop();
                            winid.push(id * 2);
                            t[id] = t[id * 2];
                        }
                        else
                        {
                            if (!winid.empty()) winid.pop();
                            if (!winid.empty()) winid.pop();
                            winid.push(id * 2 - 1);
                            t[id] = t[id * 2 - 1];
                        }
                    }
                    if (g[round][id] == '0')
                    {
                        if (t[id * 2] < round)
                        {
                            if (!winid.empty()) winid.pop();
                            if (!winid.empty()) winid.pop();
                            winid.push(id * 2);
                            t[id] = t[id * 2];
                        }
                        else
                        {
                            if (!winid.empty()) winid.pop();
                            if (!winid.empty()) winid.pop();
                            winid.push(id * 2 - 1);
                            t[id] = t[id * 2 - 1];
                        }
                    }
                }
                c[i] /= 2;
            }
            int winner = winid.front();
            if (i == 1) ans = winner;
            else ans ^= (winner * i);
        }
        cout << ans << "\n";
    }
    return 0;
}
