#include<bits/stdc++.h>
using namespace std;
char mp[10005][1005];
bool vis[1005][1005];
const int posx[]={0,1,0,-1};
const int posy[]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){int N,M,K,x,y,d,nx,ny,ans=1;
    cin>>N>>M>>K>>x>>y>>d;
    for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++)
        cin>>mp[i][j];
    memset(vis,0,sizeof(vis));
    vis[x][y]=1;
    while(K--){
        nx=x+posx[d];
        ny=y+posy[d];
        if(nx<1 || nx>N || ny<1 || ny>M || mp[nx][ny]!='.')d=(d+1)%4;
        else x=nx,y=ny;

        if(vis[x][y]==0)ans++;
        vis[x][y]=1;
    }
cout<<ans<<endl;;}
}
