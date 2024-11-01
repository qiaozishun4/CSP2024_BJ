#include<bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    for(int l = 1; l <= t; l++)
    {
        int n, m, k, x, y, d;
        cin >> n >> m >> k >> x >> y >> d;
        char a[1005][1005];
        bool flag[1005][1005];
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                flag[i][j] = 0;
            }
        }
        flag[x][y] = 1;
        for(int i = 1; i <= k; i++)
        {
            if(x + dx[d] < 1 || x + dx[d] > n || y + dy[d] < 1 || y + dy[d] > m || a[x + dx[d]][y + dy[d]] == 'x') d = (d + 1) % 4;
            else
            {
                x += dx[d];
                y += dy[d];
            }
            flag[x][y] = 1;
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(flag[i][j] == 1)
                    cnt++;
        cout << cnt << endl;
    }
    return 0;
}