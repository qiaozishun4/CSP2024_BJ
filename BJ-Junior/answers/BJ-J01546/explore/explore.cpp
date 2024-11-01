#include<bits/stdc++.h>
using namespace std;
char mp[1005][1005]={};
bool vis[1005][1005]={};
int xx[4]={0,1,0,-1},yy[4]={1,0,-1,0};
int t;
int n,m,k;
int xxx,yyy,ddd;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>xxx>>yyy>>ddd;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) cin>>mp[i][j];
        int x=xxx,y=yyy,d=ddd;
        int num=0;
        for(int i=0;i<k;i++)
        {
            if(!vis[x][y])
            {
                vis[x][y]=true;
                num++;
            }
            if((mp[x+xx[d]][y+yy[d]]=='.')&&(x+xx[d]<=n&&y+yy[d]<=m))
            {
                x=x+xx[d],y=y+yy[d];
                if(!vis[x][y])
                {
                    vis[x][y]=true;
                    num++;
                }
            }
            else d=(d+1)%4;
        }
        cout<<num<<endl;
    }
}
