#include <bits/stdc++.h>
using namespace std;

vector<int> v[200005], vis[200005], vis2[200005];

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n, K, q;
        cin >> n >> K >> q;
        for (int i = 1; i <= n; ++i)
        {
            v[i].clear();
            vis[i].clear();
            vis2[i].clear();
            int len;
            cin >> len;
            for (int j = 1; j <= len;++j)
            {
                int x;
                cin >> x;
                v[i].push_back(x);
                vis[i].push_back(0);
                vis2[i].push_back(0);
            }
        }
        while (q--)
        {
            int x, y;
            cin >> x >> y;
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 0; j < v[i].size(); ++j)
                {
                    if (v[i][j] == 1) vis[i][j] = 1;
                }
            }
            while (x--)
            {
                for (int i = 1; i <= n; ++i)
                {
                    for (int j = 0; j < v[i].size(); ++j)
                    {
                        for (int k = 2; k <= K; ++k)
                        {
                            if (j + k >= v[i].size()) continue;
                            vis2[i][j + k] = 1;
                        }
                    }
                }
                for (int i = 1; i <= n; ++i)
                {
                    for (int j = 0; j < v[i].size(); ++j)
                    {
                        vis[i][j] = 0;
                    }
                }
                for (int i = 1; i <= n; ++i)
                {
                    for (int j = 0; j < v[i].size(); ++j)
                    {
                        for (int ii = 1; ii <= n; ++ii)
                        {
                            if (ii == i) continue;
                            for (int jj = 1; jj <= v[ii].size(); ++jj)
                            {
                                if (v[i][j] == v[ii][jj])
                                {
                                    vis[ii][jj] = vis2[i][j];
                                }
                            }
                        }
                    }
                }
                for (int i = 1; i <= n; ++i)
                {
                    for (int j = 0; j < v[i].size(); ++j)
                    {
                        vis2[i][j] = 0;
                    }
                }
            }
            int ans = 0;
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 0; j < v[i].size(); ++j)
                {
                    if (v[i][j] == y) ans |= vis[i][j];
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
