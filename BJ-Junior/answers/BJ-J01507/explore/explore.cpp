#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,bex,bey,bed,ans,nowx,nowy,nowd,step;
char mapp[1010][1010];
bool vis[1010][1010];
int disx[]={0,1,0,-1};
int disy[]={1,0,-1,0};
bool check(int x,int y){
    if(x>=1 && x<=n && y>=1 && y<=m && mapp[x][y]=='.'){
        return 1;
    }else{
        return 0;
    }
    return 0;
}
int solve(){
    if(vis[nowx][nowy]==0){
        ans++;
        vis[nowx][nowy]=1;
    }
    if(step>=k){
        return -1;
    }

    for(int i=0;i<4;i++){
        int xb=nowx+disx[nowd],yb=nowy+disy[nowd];
        if(step>=k){
            return -1;
        }
        if(check(xb,yb)){
            step++;
            nowx=xb;
            nowy=yb;
            return 0;
        }else{
            nowd=(nowd+1)%4;
            step++;
        }
    }
    return 0;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        step=0;
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>nowx>>nowy>>nowd;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mapp[i][j];
            }
        }
        while(solve()!=-1){}
        cout<<ans<<'\n';
    }
    return 0;
}

