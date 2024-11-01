#include<bits/stdc++.h>
using namespace std;
const int N=1007;
int t,n,m,k;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0},px,py,pd;
bool vis[N][N];
char c[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d%d",&n,&m,&k,&px,&py,&pd);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=0;
            }
            scanf("%s",c[i]+1);
        }
        vis[px][py]=1;
        for(int i=1;i<=k;i++){
            int nx=px+dx[pd],ny=py+dy[pd];
            if(nx>=1&&ny>=1&&nx<=n&&ny<=m&&c[nx][ny]=='.'){
                px=nx,py=ny;vis[px][py]=1;
            }else{
                pd=(pd+1)%4;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j])++ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
