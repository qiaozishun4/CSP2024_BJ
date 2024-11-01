#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k,x,y,d,cnt=1;
        cin>>n>>m>>k>>x>>y>>d;
        vis[x][y]=1;
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i = 1; i<=k; i++)
        {
            int xx=x+dx[d],yy=y+dy[d];
            if(a[xx][yy]=='x'||xx<1||xx>n||yy<1||yy>m)
            {
                d=(d+1)%4;
                xx=x+dx[d],yy=y+dy[d];
                continue;
            }
            x=xx,y=yy;
            if(!vis[x][y]) cnt++;
            vis[x][y]=1;
        }
        cout<<cnt<<endl;
        memset(vis,0,sizeof(vis));
    }
    return 0;
}