#include <bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d;
int ans;
char mp[1010][1010];
bool vis[1010][1010];
void move(int fx){
    if(fx==0){
        if(y<m && mp[x][y+1]=='.') y++,vis[x][y]=true;
        else d=(d+1)%4;
    }
    if(fx==1){
        if(x<n && mp[x+1][y]=='.') x++,vis[x][y]=true;
        else d=(d+1)%4;
    }
    if(fx==2){
        if(y>1 && mp[x][y-1]=='.') y--,vis[x][y]=true;
        else d=(d+1)%4;
    }
    if(fx==3){
        if(x>1 && mp[x-1][y]=='.') x--,vis[x][y]=true;
        else d=(d+1)%4;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x>>y>>d;
        ans=0;
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) cin>>mp[i][j];
        }
        vis[x][y]=true;
        while(k--) move(d);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}