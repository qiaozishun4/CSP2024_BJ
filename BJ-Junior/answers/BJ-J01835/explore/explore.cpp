#include<bits/stdc++.h>
using namespace std;
int n,m,k,t;
char a[1005][1005];
bool vis[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        int ans=1,x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        vis[x][y]=1;
        for(int i=1;i<=k;i++)
        {
            int l,r;
            if(d==0) l=x,r=y+1;
            if(d==1) l=x+1,r=y;
            if(d==2) l=x,r=y-1;
            if(d==3) l=x-1,r=y;
            if(l>=1&&l<=n&&r>=1&&r<=m&&a[l][r]=='.')
            {
                if(!vis[l][r]) ans++,vis[l][r]=1;
                x=l,y=r;
            }
            else d=(d+1)%4;
        }
        cout<<ans<<endl;
        memset(vis,0,sizeof(vis));
    }
    return 0;
}