#include<bits/stdc++.h>
#define int long long
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char mp[1005][1005];
bool vis[1005][1005];
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(mp,0,sizeof mp);
        memset(vis,0,sizeof vis);
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        x--,y--;
        vis[x][y]=1;
        for(int i=0;i<n;i++){
            cin>>mp[i];
        }
        for(int i=1;i<=k;i++){
            int sx=x+dx[d];
            int sy=y+dy[d];
            if(sx<0||sx>=n||sy<0||sy>=m){
                d++;
                if(d>=4){
                    d=0;
                }
            }
            else if(mp[sx][sy]=='x'){
                d++;
                if(d>=4){
                    d=0;
                }
            }
            else{
                vis[sx][sy]=1;
                x=sx;
                y=sy;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1){
                  ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
