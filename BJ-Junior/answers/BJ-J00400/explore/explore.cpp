#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char mp[1020][1020];
bool visit[1020][1020];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int cnt=0;
        memset(visit,0,sizeof(visit));
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>mp[i][j];
        while(k--)
        {
            int nx=x+dx[d],ny=y+dy[d];
            if(nx>0&&nx<=n&&ny>0&&ny<=m&&mp[nx][ny]=='.')
            {
                x=nx,y=ny;
                if(!visit[x][y])
                    cnt++;
                visit[x][y]=1;
            }
            else
                d=(d+1)%4;
        }
        cout<<cnt+1<<endl;
    }
    return 0;
}