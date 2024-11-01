#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e3 + 10;
int n,m,k;
int x0,y0,d0;
char mp[N][N];
bool vis[N][N];
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
struct node{
    int x,y,step;
};
void bfs(){
    vis[x0][y0] = true;
    queue<node> q;
    q.push({x0,y0,0});
    while(!q.empty()){
        node t = q.front();
        q.pop();
        if(t.step == k){
            return ;
        }
        int nx = t.x + dx[d0],ny = t.y + dy[d0];
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] == '.'){
            q.push({nx,ny,t.step + 1});
            vis[nx][ny] = true;
        }
        else{
            d0 = (d0 + 1) % 4;
            q.push({t.x,t.y,t.step + 1});
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T -- ){
        int ans = 0;
        memset(vis,false,sizeof(vis));
        scanf("%d %d %d",&n,&m,&k);
        scanf("%d %d %d",&x0,&y0,&d0);
        for(int i=1;i<=n;i++){
            scanf("%s",mp[i] + 1);
        }
        bfs();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans += vis[i][j];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
