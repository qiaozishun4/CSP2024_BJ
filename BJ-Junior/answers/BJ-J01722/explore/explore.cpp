#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
char a[N][N];
bool vis[N][N];
int n, m, k;
queue<pair<int, int> >q;
int dis[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
inline int bfs(int x, int y, int d)
{
    memset(vis, 0, sizeof(vis));
    while(q.size())
        q.pop();
    q.push(make_pair(x, y));
    vis[x][y] = 1;
    int cnt = 0, ans = 1;
    while(cnt < k && q.size())
    {
        pair<int, int>cur = q.front();
        if(1 <= cur.first + dis[d][0] && cur.first + dis[d][0] <= n
           && 1 <= cur.second + dis[d][1] && cur.second + dis[d][1] <= m
           && a[cur.first + dis[d][0]][cur.second + dis[d][1]] == '.')
        {
            q.pop();
            q.push(make_pair(cur.first + dis[d][0], cur.second + dis[d][1]));
            if(!vis[cur.first + dis[d][0]][cur.second + dis[d][1]])
                ans++;
            vis[cur.first + dis[d][0]][cur.second + dis[d][1]] = 1;
        }
        else d = (d + 1) % 4;
        cnt++;
    }
    return ans;
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T, x0, y0, d0;
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> k >> x0 >> y0 >> d0;
        for(int i = 1;i <= n;++i)
            scanf("%s", a[i] + 1);
        cout << bfs(x0, y0, d0) << "\n";
    }
    return 0;
}
