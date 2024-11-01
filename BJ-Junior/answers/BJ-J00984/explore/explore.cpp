#include<bits/stdc++.h>

using namespace std;
long long n, m, k;
long long x, y, d;
const int N = 1010;
char a[N][N];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool vis[N][N];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
	int T;
	cin >> T;
	while(T -- )
    {
        memset(vis, 0, sizeof vis);
        scanf("%lld%lld%lld", &n, &m, &k);
        scanf("%lld%lld%lld", &x, &y, &d);
        vis[x][y] = true;
        for(int i = 1; i <= n; i ++ )
        {
            for(int j = 1; j <= m; j ++ )
            {
               cin >> a[i][j];
            }
        }
        int ans = 1;
        while(k > 0)
        {
            int s = 0;
            while((x + dx[d] > n || x + dx[d] < 1 || y + dy[d] > m || y + dy[d] < 1) || a[x + dx[d]][y + dy[d]] == 'x')
            {
                d = (d + 1) % 4;
                s ++ ;
                k -- ;
                if(s == 4 || k == 0) break;
            }

            if(s == 4 || k == 0) break;
            x = x + dx[d], y = y + dy[d];
            k -- ;
            if(vis[x][y] == 0)
            {
                ans ++ ;
                vis[x][y] = true;
            }

        }
        printf("%d\n", ans);
    }
	return 0;
}
