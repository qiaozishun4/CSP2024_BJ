#include <bits/stdc++.h>
#define int long long
using namespace std;
const int D[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bitset<1005>vis[1005];
char mp[1005][1005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        for(int i=0;i<=1000;++i)vis[i].reset();
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        vis[x][y]=1;
        for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>mp[i][j];
        int ans=1;
        while(k--){
            int nx=x+D[d][0],ny=y+D[d][1];
            if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny]=='x')d=(d+1)%4;
            else{
                x=nx;
                y=ny;
                if(!vis[x][y]){
                    vis[x][y]=1;
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}