#include<bits/stdc++.h>
using namespace std;
int ans;
int f[4][2]={0,1,1,0,0,-1,-1,0};
int n,m,k;
int x,y,d;
int vis[1010][1010];
char a[1010][1010];
void dfs(int x,int y,int d,int ci){

    if(vis[x][y]==0){
        ans++;
        vis[x][y]=1;
        //cout<<ans<<endl;
    }
    if(ci>=k){
        return;
    }
    int xx=x+f[d][0];
    int yy=y+f[d][1];
    if(a[xx][yy]=='.'&&xx>=1&&xx<=n&&yy>=1&&yy<=m){
        //cout<<xx<<" "<<yy<<" "<<d<<" "<<ci+1<<" ";
        dfs(xx,yy,d,ci+1);
    }
    else{
        //cout<<x<<" "<<y<<" "<<(d+1)%4<<" "<<ci+1<<endl;
        dfs(x,y,(d+1)%4,ci+1);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int w=1;w<=t;w++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        ans=0;
        dfs(x,y,d,0);
        cout<<ans<<endl;
    }
    return 0;
}
