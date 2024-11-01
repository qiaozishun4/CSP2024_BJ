#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,k,r,c,dir,ans;
char maze[1010][1010];
bool vis[1010][1010];
int d[][2]={{0,1},{1,0},{0,-1},{-1,0}};
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while (t--){
        memset(vis,false,sizeof(vis));
        ans=0;
        cin>>n>>m>>k>>r>>c>>dir;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin>>maze[i][j];
            }
        }
        vis[r][c]=true;
        ans++;
        for (int i=1;i<=k;i++){
            int dr=r+d[dir][0],dc=c+d[dir][1];
            if (dr<1 || dc<1 || dr>n || dc>m || maze[dr][dc]=='x'){
                dir=(dir+1)%4;
            }
            else {
                r=dr;
                c=dc;
                if (!vis[r][c]){
                    ans++;
                    vis[r][c]=true;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
