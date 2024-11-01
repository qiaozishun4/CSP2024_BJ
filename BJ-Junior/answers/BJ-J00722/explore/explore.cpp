#include<bits/stdc++.h>
using namespace std;
int g[1010][1010], n, m;
bool vis[1010][1010];
bool chk(int x, int y) {
    return x>=1&&x<=n&&y>=1&&y<=m&&!g[x][y];
}
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin>>t;
    while(t--) {
        memset(g, 0, sizeof(g));
        memset(vis, false, sizeof(vis));
        int k, x, y, d, e;
        long long cnt=0;
        char c;
        cin>>n>>m>>k>>x>>y>>d;
        vis[x][y]=true;
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=m;j++) {
                cin>>c;
                if(c=='x') {
                    g[i][j]=1;
                }
            }
        }
        for(int i = 1;i<=k;i++) {
            int nx, ny;
            if(d==0) {
                nx=x, ny=y+1;
            } else if(d==1) {
                nx=x+1, ny=y;
            } else if(d==2) {
                nx=x, ny=y-1;
            } else if(d==3) {
                nx=x-1, ny=y;
            }
            if(chk(nx, ny)) {
                x=nx, y=ny;
                vis[x][y]=true;
            } else {
                d=(d+1)%4;
            }
        }
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=m;j++) {
                cnt+=vis[i][j];
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}