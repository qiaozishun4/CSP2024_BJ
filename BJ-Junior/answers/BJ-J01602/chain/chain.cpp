#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int r[N], c[N], s[N][N];
vector<int> v1[N], v2[N];
bool f;
int n, k, q;
void dfs(int q1, int r1, int cur, int x, int las)
{
    //cout << x << " " << r1 << "+++";
    if(cur > q1) return;
    if(x == r1)
    {
        f = 1;
        return;
    }
    for(int i = 0;i < v1[x].size();i++)
    {
        if(v1[x][i] == las) continue;
        for(int j = min(v2[x][i] + 1, int(v1[x].size()));j <= min(v2[x][i] + k - 1, int(v1[x].size()));j++) dfs(q1, r1, cur + 1, s[v1[x][i]][j], v1[x][i]);
    }
}
int main()
{
    freopen("chain1.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> q;
        for(int i = 1;i <= n;i++)
        {
            int l;
            cin >> l;
            for(int j = 1;j <= l;j++)
            {
                cin >> s[i][j];
                v1[s[i][j]].push_back(i);
                v2[s[i][j]].push_back(j);
            }
        }
        for(int i = 1;i <= q;i++)
        {
            cin >> r[i] >> c[i];
            f = 0;
            dfs(r[i], c[i], 0, 1, -1);
            if(f == 1) cout << 1;
            else cout << 0;
            cout <<"\n";
        }
    }
    return 0;
}
