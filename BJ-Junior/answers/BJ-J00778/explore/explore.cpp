#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=1e3+5;
const int dst[][2]={{0,1},{1,0},{0,-1},{-1,0}};
char a[N][N];
bool vis[N][N];

void solve(){
    memset(vis,0,sizeof(vis));
    int n,m,k,x,y,d;
    cin>>n>>m>>k>>x>>y>>d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    vis[x][y]=true;
    while(k--){
        int xx=x+dst[d][0];
        int yy=y+dst[d][1];
        if(xx<1 || xx>n || yy<1 || yy>m || a[xx][yy]=='x'){
            d=(d+1)%4;
        }else{
            x=xx,y=yy;
            vis[xx][yy]=true;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cnt+=vis[i][j];
        }
    }
    cout<<cnt<<'\n';
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
