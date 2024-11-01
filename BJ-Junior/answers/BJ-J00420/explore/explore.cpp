#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int T, n, m, k, x, y, d, cnt = 1;
bool vis[1005][1005];
string s[1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin >> T;
    while(T --)
    {
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1; i <= n; i ++)
            cin >> s[i];

        vis[x][y] = true;
        for(int i = 1; i <= k; i ++)
        {
            int x_new = x + dx[d], y_new = y + dy[d];
            if(x_new < 1 || x_new > n || y_new < 1 || y_new > m)
            {
                d = (d + 1) % 4;
                continue;
            }
            if(s[x_new][y_new - 1] == 'x')
            {
                d = (d + 1) % 4;
                continue;
            }
            x = x_new;
            y = y_new;
            cnt += (vis[x][y] == false);
            vis[x][y] = true;
        }

        cout << cnt << endl;

        cnt = 1;
        memset(vis, 0, sizeof(vis));
    }

    return 0;
}
