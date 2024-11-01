#include<bits/stdc++.h>
using namespace std;
bool vis[1005][1005];
char mp[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k,x,y,d,ans=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>mp[i][j];
                vis[i][j]=0;
            }
        }
        vis[x][y]=1;
        ans++;
        while(k--)
        {
            int tx=x,ty=y;
            if(d==0) ty++;
            else if(d==1) tx++;
            else if(d==2) ty--;
            else tx--;
            if(0<tx&&tx<=n&&0<ty&&ty<=m&&mp[tx][ty]=='.')
            {
                x=tx,y=ty;
                if(!vis[x][y])
                {
                    vis[x][y]=1;
                    ans++;
                }
            }
            else d=(d+1)%4;
        }
        cout<<ans<<endl;
    }
    return 0;
}
