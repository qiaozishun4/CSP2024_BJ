#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n, k, q, l[N], cnt, P[N], dp[105][N][N], v[N][N];
vector<int> pos[N][N];
map <int, int> mp[N], vis;
void ipt ()
{
    scanf ("%d%d%d", &n, &k, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf ("%d", &l[i]);
        for (int j = 1; j <= l[i]; j++)
        {
            int x; scanf ("%d", &x);
            v[i][j] = x;
            if (!vis[x]) vis[x] = ++cnt, P[cnt] = x;
        }
        for (int j = 1; j <= l[i]; j++)
        {
            pos[i][vis[v[i][j]]].push_back (j);
        }
    }
    cnt = 0;
    vis.clear();
}
void solve ()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < pos[i][vis[1]].size(); j++)
        {
            int xd = pos[i][vis[1]][j];
            dp[0][i][xd] = 1;
        }
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int w = 1; w <= l[i]; w++)
            {
                int now = v[j][w];
                for (int g = 0; g < pos[j][vis[now]].size(); g++)
                {
                    int Pos = pos[j][vis[now]][g];
                    for (int h = 1; h < k && Pos - h >= 1; h++)
                    {
                        int to = v[i][Pos - h];
                        int To = vis[to];
                        for (int xd = 1; xd <= n; xd++)
                        {
                            for (int Xd = 0; Xd < pos[xd][To].size(); Xd++)
                            {
                                int kkk = pos[xd][To][Xd];
                                dp[i][j][w] = max (dp[i][j][w], dp[i - 1][xd][kkk]);
                            }
                        }
                    }
                }
            }
        }
    }
    while (q--)
    {
        int r, c;
        scanf ("%d%d", &r, &c);
        c = vis[c];
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < pos[i][c].size(); j++)
            {
                int v = pos[i][c][j];
                ans = max (ans, dp[r][i][v]);
            }
        }
        if (r == 1 && l == 1) cout << 0;
        else cout << ans << endl;
    }
}
int main ()
{
    freopen ("chain.in", "r", stdin);
    freopen ("chain.out", "w", stdout);
    int T; cin >> T;
    while (T--)
    {
        ipt ();
        solve ();
    }
    return 0;
}