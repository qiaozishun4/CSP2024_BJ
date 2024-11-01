#include<bits/stdc++.h>
#define int long long
using namespace std;

int t,n,m,k,d;
char a[1005][1005];
int vis[1005][1005];

pair <int,int> op(int x,int y,int d)
{
    if(d==0)return make_pair(x,y+1);
    if(d==1)return make_pair(x+1,y);
    if(d==2)return make_pair(x,y-1);
    if(d==3)return make_pair(x-1,y);
}

signed main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int x,y,ans=0;
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        vis[x][y]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=k;i++)
        {
            int xx=op(x,y,d).first,yy=op(x,y,d).second;
            if(xx<1||xx>n||yy<1||yy>m)
            {
                d=(d+1)%4;
                continue;
            }
            else
            {
                if(a[xx][yy]=='x')
                {
                    d=(d+1)%4;
                    continue;
                }
                else
                {
                    vis[x][y]=1;
                    x=xx;y=yy;
                    vis[x][y]=1;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(vis[i][j])
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
