#include <bits/stdc++.h>
#define int long long
using namespace std;
char mp[1005][1005];
int vis[1005][1005];
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=0;i<n;i++){
            cin>>mp[i];
        }
        x--,y--;
        int s=0;
        vis[x][y]=1;
        s++;
        for(int i=1;i<=k;i++){
            int nx,ny;
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
            if(0<=nx&&nx<n&&0<=ny&&ny<m&&mp[nx][ny]!='x'){
                if(vis[nx][ny]==0){
                    s++;
                }
                vis[nx][ny]=1;
                x=nx;
                y=ny;
            }else{
                d++;
                d%=4;
            }
            //cout<<vis[x][y]<<endl;
        }
        cout<<s<<endl;
        memset(vis,0,sizeof vis);
        memset(mp,' ',sizeof mp);
    }
    return 0;
}
