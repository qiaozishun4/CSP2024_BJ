#include <bits/stdc++.h>
using namespace std;

void calc()
{
    int n, m, k;
    cin >> n >> m >> k;
    int x, y, d;
    cin >> x >> y >> d;
    bool vis[1005][1005];
    char can[1005][1005];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            cin >> can[i][j];
        }
    vis[x][y] = 1;

    while(k--)
    {
        int fx = x, fy = y;
        if(d == 0) fy++;
        if(d == 1) fx++;
        if(d == 2) fy--;
        if(d == 3) fx--;
        if(can[fx][fy] == 'x')
        {
            d = (d+1)%4; continue;
        }
        if(fx<1 || fx>n || fy<1 || fy>m)
        {
            d = (d+1)%4; continue;
        }
        x = fx, y = fy;
        vis[x][y] = 1;
    }

    int cnt = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(vis[i][j])
                cnt++;
    cout << cnt << endl;
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        calc();
    }
    return 0;
}