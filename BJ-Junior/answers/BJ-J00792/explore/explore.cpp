#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
char mp[N][N];
bool vis[N][N];
int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int T;
    cin>>T;
    while(T--) {
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));

        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin>>mp[i][j];
            }
        }
        vis[x][y]=true;

        while(k--) {
            int nx,ny;
            if(d==0) {
                nx=x,ny=y+1;
            }
            else if(d==1) {
                nx=x+1,ny=y;
            }
            else if(d==2) {
                nx=x,ny=y-1;
            }
            else if(d==3) {
                nx=x-1,ny=y;
            }
            if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny]=='x') {
                d=(d+1)%4;
            }
            else {
                vis[nx][ny]=true;
                x=nx,y=ny;
            }
        }

        long long ans=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(vis[i][j]) {
                    ans++;
                }
            }
        }

        cout<<ans<<endl;
    }

	return 0;
}
