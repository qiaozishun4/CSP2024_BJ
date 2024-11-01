#include<bits/stdc++.h>
using namespace std;
const int N=1005;
bool vis[N][N],vis2[N][N];
int n,m,k,ans;
int xx,yy,dd;
void dfs(int x,int y,int dr,int sum){
    vis2[x][y] = true;
    if(sum > k) return;
    int fx,fy;
    if(dr == 0){
       fx = x , fy = y+1;
    }
    else if(dr == 1){
        fx = x+1 , fy = y;
    }
    else if(dr == 2){
        fx = x , fy = y-1;
    }
    else if(dr == 3){
        fx = x-1 , fy = y;
    }
    if(vis[fx][fy]) dfs(fx,fy,dr,sum+1);
    else{
        int drc = (dr+1)%4;
        dfs(x,y,drc,sum+1);
    }
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&n,&m,&k);
        scanf("%d %d %d",&xx,&yy,&dd);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                vis[i][j] = vis2[i][j] = false;
        for(int i=1;i<=n;i++){
            string s; cin>>s;
            for(int j=1;j<=m;j++){
                if(s[j-1] == '.') vis[i][j] = true;
            }
        }
        dfs(xx,yy,dd,1);
        ans = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(vis2[i][j]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
