#include<bits/stdc++.h>
using namespace std;
int v[1005][1005],fx[5]={0,1,0,-1},fy[5]={1,0,-1,0};
char ma[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>ma[i][j];
            }
        }
        int nx=x,ny=y;
        int x1,y1;
        v[nx][ny]=1;
        for(int i=1;i<=k;i++)
        {
            x1=nx+fx[d],y1=ny+fy[d];
            if(x1>0&&x1<=n&&y1>0&&y1<=m&&ma[x1][y1]=='.')
            {
                nx=x1,ny=y1;
                v[nx][ny]=1;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(v[i][j]==1)ans++;
            }
        }
        cout<<ans<<endl;
        memset(v,0,sizeof(v));
        memset(ma,0,sizeof(ma));
    }
    return 0;
}