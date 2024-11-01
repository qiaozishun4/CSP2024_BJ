#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d;
ll n,m,k;
char mp[1005][1005];
bool vis[1005][1005];
void dfs(ll x,ll y){
    while(k--){
        vis[x][y]=1;
        ll nx,ny;
        if(d==0){
            nx=x,ny=y+1;
        }
        if(d==1){
            nx=x+1,ny=y;
        }
        if(d==2){
            nx=x,ny=y-1;
        }
        if(d==3){
            nx=x-1,ny=y;
        }
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.'){
            x=nx,y=ny;
            vis[nx][ny]=1;
        }else{
            d=(d+1)%4;
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ll T;
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=0;
            }
        }
        ll x,y;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        dfs(x,y);
        ll cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]) cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
/*
1
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/
