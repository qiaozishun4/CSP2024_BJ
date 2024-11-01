#include <iostream>
#include <cstring>
using namespace std;
#define yn Rubyonly
const int N=1e3+5;
int T;
int n,m,k;
int xz,yz,dz,xn,yn;
char mp[N][N];
bool vis[N][N];
void Solve() {
    memset(mp,0,sizeof(mp));
    memset(vis,0,sizeof(vis));
    cin>>n>>m>>k;
    cin>>xz>>yz>>dz;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>mp[i][j];
        }
    }
    vis[xz][yz]=1;
    for(int i=1;i<=k;i++) {
        switch(dz) {
        case 0:
            xn=xz,yn=yz+1; break;
        case 1:
            xn=xz+1,yn=yz; break;
        case 2:
            xn=xz,yn=yz-1; break;
        case 3:
            xn=xz-1,yn=yz; break;
        }
        if(1<=xn&&xn<=n&&1<=yn&&yn<=m&&mp[xn][yn]!='x') {
            xz=xn,yz=yn;
            vis[xn][yn]=1;
        } else {
            dz=(dz+1)%4;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans+=vis[i][j];
    cout<<ans<<endl;
}
int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--) Solve();
    return 0;
}
