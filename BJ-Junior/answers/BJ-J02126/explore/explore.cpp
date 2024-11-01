#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,T;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
char mp[3005][3005];
bool vis[3005][3005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        int ans=1;
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) vis[i][j]=0;
        vis[x][y]=1;
        while(k--){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.') x=nx,y=ny;
            else d=(d+1)%4;
            if(!vis[x][y]) ans++;
            vis[x][y]=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
