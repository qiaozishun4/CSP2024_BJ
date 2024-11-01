#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int T, n, k, q, r, c, ans;
int l[N];
vector<int> a[N];
map<int, int> b[N];
int vis[N];

void dfs(int step, int x, int y)
{
    if(ans) return ;
    if(step > r)
    {
        if(a[x][y] == c) ans = 1;
        return ;
    }
    for(int i = 2; i <= min(k, l[x]-y+1); i ++)
    {
        int j = y+i-1;
        int t = a[x][j];
        for(int l = 1; l <= n; l ++)
        {
            if(l == x) continue;
            if(!b[l].count(t)) continue;
            int tmp = a[l][b[l][t]];
            dfs(step+1, l, b[l][t]);
        }
    }
}

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        cin >> n >> k >> q;
        memset(vis, 0x3f, sizeof(vis));
        for(int i = 1; i <= n; i ++)
        {
            cin >> l[i];
            int last = -1;
            for(int j = 1; j <= l[i]; j ++)
            {
                int c;
                cin >> c;
                if(last != -1) vis[c] = min(vis[c], j-last+1);
                if(c == 1) last = j;
                a[i].push_back(c);
                b[i][c] = j;
            }
        }
        while(q--)
        {
            cin >> r >> c;
            if(r == 1)
            {
                if(vis[c] <= k) cout << 1 << '\n';
                else cout << 0 << '\n';
                continue;
            }
            if(vis[c] == 0x3f)
            {
                cout << 0 << '\n';
            }
            else
            {
                ans = 0;
                for(int i = 1; i <= n; i ++)
                {
                    for(int j = 1; j <= l[i]; j ++)
                    {
                        if(a[i][j]==1) dfs(1, i, j);
                        if(ans == 1) break;
                    }
                    if(ans) break;
                }
                cout << ans;
            }
        }
    }
    return 0;
}
