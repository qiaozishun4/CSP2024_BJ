#include<iostream>

using namespace std;

const int N = 1010;
char a[N][N];
bool vis[N][N];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n, m, k, x, y, d;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin >> a[i][j], vis[i][j] = false;
        vis[x][y] = true;
        int nx = x, ny = y;
        while(k--)
        {
            nx = x, ny = y;
            if(d == 0) ny++;
            else if(d == 1) nx++;
            else if(d == 2) ny--;
            else if(d == 3) nx--;
            if(a[nx][ny] == 'x' || nx < 1 || nx > n || ny < 1 || ny > m)
            {
                d = (d + 1) % 4;
                continue;
            }
            vis[nx][ny] = true;
            x = nx, y = ny;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                ans += vis[i][j];
        cout << ans << endl;
    }
    return 0;
}
