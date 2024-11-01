#include<bits/stdc++.h>
using namespace std;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char mp[1015][1015];
bool vis[1015][1015];
int n,m,t,k,d,x,y,ans;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        for(int i=0;i<=1004;++i) for(int j=0;j<=1004;++j) mp[i][j]=vis[i][j]=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        vis[x][y]=true;
        for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin>>mp[i][j];
        while(k--){
            if(mp[x+dx[d]][y+dy[d]]=='.') x+=dx[d],y+=dy[d];
            else d++,d%=4;
            vis[x][y]=true;
        }
        for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(vis[i][j]==true) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
