#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int t,n,m,k;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char g[1010][1010];
bool vis[1010][1010];

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>g[i][j];
            }
        }
        vis[x][y]=1;
        for(int i=1;i<=k;i++)
        {
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(nx>n||nx<1||ny>m||ny<1||g[nx][ny]=='x')
            {
                d++;
                d%=4;
                continue;
            }
            else
            {
                x=nx;
                y=ny;
                vis[x][y]=1;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(vis[i][j])
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}
