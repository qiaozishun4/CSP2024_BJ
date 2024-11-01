#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool b[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(b,0,sizeof(b));
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        int ans = 0;
        b[x][y] = 1;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i = 1;i <= k;i++)
        {
            int nx = x,ny = y;
            if(d == 0) ny++;
            if(d == 1) nx++;
            if(d == 2) ny--;
            if(d == 3) nx--;
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.')
            {
                x = nx;
                y = ny;
                b[nx][ny] = 1;
            }
            else
            {
                d = (d + 1) % 4;
            }
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                if(b[i][j] == 1)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}