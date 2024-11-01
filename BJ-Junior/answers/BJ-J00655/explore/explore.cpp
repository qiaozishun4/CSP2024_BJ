#include<bits/stdc++.h>
using namespace std;
char a[1002][1002];
bool f[1002][1002];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k,x,y,d,ans=1,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        f[x][y]=1;
        for(int i=1;i<=k;i++)
        {
            int nx=x+dx[d],ny=y+dy[d];
            //cout<<"x"<<nx<<" "<<"y"<<ny<<"\n";
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]!='x')
            {
                x=nx,y=ny;
                //cout<<"x"<<nx<<" "<<"y"<<ny<<"\n";
                f[x][y]=1;
            }
            else
            {
                d=(d+1)%4;
                //cout<<"\\\n";
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(f[i][j]==1)
                {
                    ans++;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                f[i][j]=0;
            }
        }
        cout<<ans-1<<"\n";
    }
    return 0;
}
