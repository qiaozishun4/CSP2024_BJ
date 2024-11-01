#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d;
char mp[1005][1005];
bool vis[1005][1005];
void go(int &a,int &b,int f){
    switch(f){
        case 0:
            b++;
            break;
        case 1:
            a++;
            break;
        case 2:
            b--;
            break;
        case 3:
            a--;
            break;
    }
}
bool check(int a,int b){
    return (mp[a][b]=='.' && a>0 && a<=n && b>0 && b<=m);
}
void solve(){
    memset(vis,0,sizeof(vis));
    int res=0;
    cin>>n>>m>>k>>x>>y>>d;
    vis[x][y]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=k;i++){
        int dx=x,dy=y;
        go(dx,dy,d);
        if(check(dx,dy)){
            vis[dx][dy]=1;
            x=dx;
            y=dy;
        }else{
            d=(d+1)%4;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vis[i][j]) res++;
        }
    }
    cout<<res<<endl;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
