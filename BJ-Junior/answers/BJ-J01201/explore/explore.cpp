#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x10,y10,d10;
char a[1005][1005]={};
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>x10>>y10>>d10;
        char a[1005][1005]={};
        int vis[1005][1005]={},ans=1;
        vis[x10][y10]=1;
        for(int i=1;i<=n;i++)
        {
            cin>>(a[i]+1);
        }
        int x=x10,y=y10,d=d10;
        for(int i=1;i<=k;i++)
        {
            int tx=x+fx[d];
            int ty=y+fy[d];
            //cout<<tx<<" "<<ty<<"\n";
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]!='x')
            {
                x=tx;
                y=ty;
                //cout<<x<<" "<<y<<"\n";
                if(!vis[x][y])
                {
                    ans++;
                    vis[x][y]=1;
                }
            }else{
                d=(d+1)%4;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
