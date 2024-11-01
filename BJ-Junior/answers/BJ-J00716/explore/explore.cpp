#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int T,n,m,k,x,y,d,ans;
char a[maxn][maxn];
int vis[maxn][maxn];
int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--) {
        memset(vis,0,sizeof(vis));
        ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        while(k--) {
            vis[x][y]=1;
            int x0=x,y0=y;
            if(d==0) y++;
            else if(d==1) x++;
            else if(d==2) y--;
            else x--;
            if(x>=1 && x<=n && y>=1 && y<=m && a[x][y]=='.') {
                if(vis[x][y]) continue;
                else {
                    ans++;
                    vis[x][y]=1;
                }
            }
            else {
                d=(d+1)%4;
                x=x0;
                y=y0;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
