#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1e3 + 10;

int n,m;
int v[N][N];
char a[N][N];
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

void dfs(int x,int y,int d,int k)
{
    v[x][y] = 1;
    if(k <= 0) return ;
    for(int i = 0; i <= 3; i++)
    {
        int nd = (d + i) % 4;
        int nx = x + dx[nd];
        int ny = y + dy[nd];
        k -= 1;
        if(k < 0) return ;
        if(nx < 1 || n < nx || ny < 1 || m < ny) continue;
        if(a[nx][ny] == 'x') continue;
        dfs(nx,ny,nd,k);
        return ;
    }
}

signed main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int k;
        cin >> n >> m >> k;
        int sx,sy,sd;
        cin >> sx >> sy >> sd;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                v[i][j] = 0;
                cin >> a[i][j];
            }
        }
        dfs(sx,sy,sd,k);
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                if(v[i][j] == 1) cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
