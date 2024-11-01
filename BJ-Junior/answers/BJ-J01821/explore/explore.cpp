#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool flag[1005][1005];
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
int main()
{
    freopen("explore.in" , "r" , stdin);
    freopen("explore.out" , "w" , stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    int n,m,k,x,y,d,cnt,nx,ny;
    cin >> t;
    while(t--)
    {
        memset(flag , 0 , sizeof(flag));
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        flag[x][y] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                cin >> a[i][j];
        }
        for(int i = 1; i <= k; i++)
        {
            nx = x + dx[d];
            ny = y + dy[d];
            if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 'x')
            {
                d = (d + 1) % 4;
                continue;
            }
            x = nx,y = ny;
            flag[x][y] = 1;
        }
        cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                cnt += flag[i][j];
        }
        cout << cnt <<"\n";
    }
    return 0;
}
