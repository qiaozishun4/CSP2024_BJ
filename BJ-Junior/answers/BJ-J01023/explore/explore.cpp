#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int n,m,k;
char a[1020][1020];
bool vis[1020][1020];

void dfs(int x,int y,int d,int step){
    //cout<<x<<" "<<y<<" "<<d<<" "<<step<<endl;

    if(step==k) return ;

    int t=d;
    int nx=x,ny=y;
    if(t==0) ny++;
    else if(t==1) nx++;
    else if(t==2) ny--;
    else if(t==3) nx--;

    if(nx>=1 && nx<=n && ny>=1 && ny<=m && a[nx][ny]=='.'){
        vis[nx][ny]=true;
        dfs(nx,ny,t,step+1);
    }else{
        t=(t+1)%4;

        dfs(x,y,t,step+1);
    }
    return ;
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int T;
    cin>>T;
    while(T--){
        memset(vis,false,sizeof(vis));
        int sx,sy,d;
        cin>>n>>m>>k>>sx>>sy>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        
        vis[sx][sy]=true;
        dfs(sx,sy,d,0);

        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]) ans++;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}