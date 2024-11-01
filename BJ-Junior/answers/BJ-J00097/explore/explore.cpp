#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int T,x,y,d,n,m,k;
string s[N];
int vis[N][N];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        n-=1;
        m-=1;
        for(int i=0;i<=n;i++)cin >> s[i];
        memset(vis,0,sizeof(vis));
        x-=1;
        y-=1;
        vis[x][y]=1;
        for(int i=1;i<=k;i++)
        {
            int nx,ny;
            if(d==0)nx=x,ny=y+1;
            if(d==1)nx=x+1,ny=y;
            if(d==2)nx=x,ny=y-1;
            if(d==3)nx=x-1,ny=y;
            if(0<=nx&&nx<=n&&0<=ny&&ny<=m&&s[nx][ny]=='.')x=nx,y=ny,vis[nx][ny]=1;
            else d=(d+1)%4;
        }
        int sum=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(vis[i][j])sum++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
