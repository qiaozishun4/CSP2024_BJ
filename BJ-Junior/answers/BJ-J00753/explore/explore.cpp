#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3;
char a[N + 5][N + 5];
bool vis[N + 5][N + 5];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int n,m,k,x,y,d;

signed main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int ans = 0;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1;i <= n;++i)
        {
            for(int j = 1;j <= m;++j)
            {
                cin >> a[i][j];
                vis[i][j] = 0;
            }
        }
        while(k--)
        {
            ans++;
            ans -= vis[x][y];
            vis[x][y] = 1;
            int tx = x + dx[d],ty = y + dy[d];
            if(1 <= tx && tx <= n && 1 <= ty && ty <= m && a[tx][ty] == '.')
            {
                x = tx;
                y = ty;
            }
            else
            {
                d = (d + 1) % 4;
            }
        }
        ans++;
        ans -= vis[x][y];
        cout << ans << endl;
    }
    return 0;
}
