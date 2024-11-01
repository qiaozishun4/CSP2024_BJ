#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int T,n,m,k,sx,sy,d;
char maps[N][N];
bool vis[N][N];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k>>sx>>sy>>d;
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>maps[i][j];
                if(i!=sx||j!=sy) vis[i][j]=0;
                else vis[i][j]=1;
            }
        }
        int cx=sx;
        int cy=sy;
        while(k--)
        {
            if(d==0)
            {
                int p=sy+1;
                if(p<=m&&maps[sx][p]=='.') 
                {
                    sy=p;
                    if(!vis[sx][p]) 
                    {
                        ans++;
                        vis[sx][p]=1;
                    }
                }
                else d=1;
            }
            else if(d==1)
            {
                int p=sx+1;
                if(p<=n&&maps[p][sy]=='.') 
                {
                    sx=p;
                    if(!vis[p][sy]) 
                    {
                        ans++;
                        vis[p][sy]=1;
                    }
                }
                else d=2;
            }
            else if(d==2)
            {
                int p=sy-1;
                if(p>0&&maps[sx][p]=='.') 
                {
                    sy=p;
                    if(!vis[sx][p]) 
                    {
                        ans++;
                        vis[sx][p]=1;
                    }
                }
                else d=3;
            }
            else
            {
                int p=sx-1;
                if(p>0&&maps[p][sy]=='.') 
                {
                    sx=p;
                    if(!vis[p][sy]) 
                    {
                        ans++;
                        vis[p][sy]=1;
                    }
                }
                else d=0;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}