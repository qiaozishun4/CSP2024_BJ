#include <bits/stdc++.h>
//#define int long long
using namespace std;
bool vis[1005][1005];
char Map[1005][1005];
int xx[]={0,1,0,-1},yy[]={1,0,-1,0};
int ans=0;
int n,m,k;
bool flag;
void dfs(int x,int y,int d,int CanBeStep){
    if(CanBeStep==0) return;
    int dx=x+xx[d],dy=y+yy[d];
    if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&Map[dx][dy]=='.'){
        if(!vis[dx][dy]) ans++;
        vis[dx][dy]=true;
        //flag=true;
        //cout<<"==== change IP add,("<<x<<","<<y<<")to("<<dx<<","<<dy<<") ====\n";
        dfs(dx,dy,d,CanBeStep-1);
    }
    else{
        //if(!flag) ans++,flag=true;
        //cout<<"==== change data d,("<<d<<")to("<<(d+1)%4<<") ====\n";
        dfs(x,y,(d+1)%4,CanBeStep-1);

    }
}
void init_array(){
    memset(Map,0,sizeof(Map));
    memset(vis,0,sizeof(vis));
    ans=0;
    flag=false;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int t;
    cin>>t;
    while(t--){

        int sx,sy,sd;
        cin>>n>>m>>k;
        cin>>sx>>sy>>sd;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>Map[i][j];
            }
        }
        vis[sx][sy]=true;
        ans++;
        dfs(sx,sy,sd,k);

        cout<<ans<<"\n";



        init_array();
    }

    return 0;
}
