#include <bits/stdc++.h>
using namespace std;
bool g[1010][1010],vis[1010][1010];
int n,m,k,x,y,d;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void solve(){
    int ct=0;
    vis[x][y]=1;
    for(int i=1;i<=k;++i){
        bool ns=g[x+dx[d]][y+dy[d]];
        if(ns){
            //printf("%d,%d->%d,%d\n",x,y,x+dx[d],y+dy[d]);
            x+=dx[d],y+=dy[d];
            vis[x][y]=1;

        }
        else{
            //printf("%d->%d\n",d,(d+1)%4);
            d+=1;
            d%=4;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(vis[i][j])++ct;
        }
    }
    cout<<ct<<endl;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(g,0,sizeof(g));
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;++i){
            string s;
            cin>>s;
            for(int j=1;j<=m;++j){
                g[i][j]=s[j-1]=='.'?1:0;
            }
        }
        solve();
    }
    return 0;
}
