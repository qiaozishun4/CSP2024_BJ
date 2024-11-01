#include<bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
char a[1005][1005];
bool vis[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        int n,m,dt,x,y,d,ans=1;
        scanf("%d%d%d",&n,&m,&dt);
        scanf("%d%d%d",&x,&y,&d);
        vis[x][y]=1;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
        for(int i=1;i<=dt;i++){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(nx<1||nx>n||ny<1||ny>m){d++;d%=4;continue;}
            if(a[nx][ny]=='x'){d++;d%=4;continue;}
            if(vis[nx][ny]){x=nx;y=ny;continue;}
            x=nx;
            y=ny;
            ans++;
            vis[nx][ny]=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
