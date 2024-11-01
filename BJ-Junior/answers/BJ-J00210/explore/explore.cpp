#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
char x;
bool a[N][N];
bool vis[N][N];
int t,n,m,k,d,sx,sy,ans;
void dfs(int x,int y,int d,int k){
    if(k==0)    return;
    if(d==0){
        if(a[x][y+1]){
            if(!vis[x][y+1])    ans++;
            vis[x][y+1]=1;
            dfs(x,y+1,d,k-1);
        }else    dfs(x,y,(d+1)%4,k-1);
    }else if(d==1){
        if(a[x+1][y]){
            if(!vis[x+1][y])    ans++;
            vis[x+1][y]=1;
            dfs(x+1,y,d,k-1);
        }else    dfs(x,y,(d+1)%4,k-1);
    }else if(d==2){
        if(a[x][y-1]){
            if(!vis[x][y-1])    ans++;
            vis[x][y-1]=1;
            dfs(x,y-1,d,k-1);
        }else    dfs(x,y,(d+1)%4,k-1);
    }else{
        if(a[x-1][y]){
            if(!vis[x-1][y])    ans++;
            vis[x-1][y]=1;
            dfs(x-1,y,d,k-1);
        }else    dfs(x,y,(d+1)%4,k-1);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>sx>>sy>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>x;
                if(x=='.')  a[i][j]=1;
                else{
                    a[i][j]=0;
                }
            }
        }
        vis[sx][sy]=1;
        dfs(sx,sy,d,k);
        cout<<++ans<<'\n';
    }
    return 0;
}
