#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
bitset<1010> vis[1010],can[1010];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
        ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=0;i<1010;i++)vis[i].reset(),can[i].reset();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                can[i][j]=c=='.';
            }
        }
        for(int i=1;i<=k;i++)
        {
            vis[x][y]=1;
            int nx=x+dx[d],ny=y+dy[d];
            if(can[nx][ny])
            {
                x=nx,y=ny;
            }
            else
            {
                d=(d+1)%4;
            }
        }
            vis[x][y]=1;
        int cnt=0;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cnt+=vis[i][j];
        cout<<cnt<<'\n';
    }
    return 0;
}