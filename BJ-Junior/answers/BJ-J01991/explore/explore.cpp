#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,ans,vis[1010][1010];
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
char a[1010][1010];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>>a[i][j];
            }
        }
        ans=1;
        memset(vis,0,sizeof(vis));
        int hx=x,hy=y,hd=d;
        vis[x][y]=1;
        while(k--)
        {
            int nx=hx+dx[hd],ny=hy+dy[hd],nd=hd;
            //cout<<nx<<" "<<ny<<" "<<nd<<" "<<ans<<endl;
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.')
            {
                if(!vis[nx][ny])
                {
                    ans++;
                    vis[nx][ny]=1;
                }
                hx=nx;
                hy=ny;
                hd=nd;
            }
            else
            {
                hd=(nd+1)%4;
            }
        }
        cout<<ans<<"\n";
    }
}

