#include<bits/stdc++.h>
using namespace std;
int n,m,k,xd[4]={0,1,0,-1},yd[4]={1,0,-1,0},ans=1;
bool vis[1100][1100],maps[1100][1100];
void dfs(int x,int y,int fx,int cnt){
    if(vis[x][y]==0)ans++,vis[x][y]=1;
    if(cnt==k)return;
    int curx=x+xd[fx];
    int cury=y+yd[fx];
    if(curx<1||cury<1||curx>n||cury>m||maps[curx][cury]==1){
        dfs(x,y,(fx+1)%4,cnt+1);
    }else{
        dfs(curx,cury,fx,cnt+1);
    }
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        ans=0;
        memset(maps,false,sizeof(maps));
        memset(vis,false,sizeof(vis));
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char x;
                cin>>x;
                if(x=='x')maps[i][j]=1;
            }
        }
        dfs(x,y,d,0);
        cout<<ans<<endl;
    }
    return 0;
}