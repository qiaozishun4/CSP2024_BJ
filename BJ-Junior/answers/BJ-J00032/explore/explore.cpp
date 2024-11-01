#include <bits/stdc++.h>
using namespace std;
int xx[4] = {0,1,0,-1};
int yy[4] = {1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        char a[1005][1005];
        int vis[1005][1005];
        int n,m,k;
        cin >> n >> m >> k;
        int x,y,d;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> a[i][j];
                vis[i][j] = 0;
            }
        }
        int sum = 1;
        while(k--)
        {
            if(a[x+xx[d]][y+yy[d]] == 'x' || x+xx[d] < 1 || x+xx[d] > n || y+yy[d] < 1 || y+yy[d] > m)
            {
                d = (d+1)%4;
            }
            else
            {
                x+=xx[d];
                y+=yy[d];
                if(vis[x][y] == 0) sum++;
                vis[x][y] = 1;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
