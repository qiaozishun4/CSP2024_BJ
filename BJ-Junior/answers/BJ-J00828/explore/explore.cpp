#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
bool vis[1005][1005]; char mp[1005][1005];
int main(){
    freopen("explore5.in","r",stdin);
    freopen("explore1.out","w",stdout);
    cin >> t;
    while(t--){
        memset(mp,0,sizeof mp);
        memset(vis,0,sizeof vis);
        int ans=0;
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        vis[x][y]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) cin >> mp[i][j];
        for(int i=1;i<=k;i++){
            int nx=x+dx[d],ny=y+dy[d];
            while(mp[nx][ny]=='x'||nx<1||nx>n||ny<1||ny>m&&i<=k)
                i++,d=(d+1)%4,nx=x+dx[d],ny=y+dy[d];
            x=nx,y=ny;
            vis[nx][ny]=1;
        }for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(vis[i][j]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
