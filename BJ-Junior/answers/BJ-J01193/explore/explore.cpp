#include <bits/stdc++.h>
using namespace std;

bool sf[1010][1010],vis[1010][1010];
int mv[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;//5e0
    cin>>t;
    while(t--)
    {
        memset(sf,0,sizeof(sf));
        memset(vis,0,sizeof(vis));
        int n,m,k,x,y,d;//1e3 1e3 1e6 1e3 1e3 3e0
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                if(c=='.')
                    sf[i][j]=true;
            }
        int cnt=1;//1e6
        vis[x][y]=true;
        while(k--)
        {
            int nx=x+mv[d][0];//2e3
            int ny=y+mv[d][1];//2e3
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&sf[nx][ny])
            {
                x=nx;
                y=ny;
                if(!vis[x][y])
                {
                    vis[x][y]=true;
                    cnt++;
                }
            }
            else
                d=(d+1)%4;
            //cout<<nx<<" "<<ny<<" "<<x<<" "<<y<<endl;
        }
        cout<<cnt<<endl;
    }

    return 0;
}
