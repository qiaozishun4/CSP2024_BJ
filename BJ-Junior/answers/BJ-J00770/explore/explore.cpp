#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

const int N=1e3+100;
char c[N][N];
int n,m,k,x,y,d;
bool vis[N][N];
void sol() {
    memset(vis,0,sizeof vis);
    cin>>n>>m>>k>>x>>y>>d; vis[x][y] = 1;
    forr(i,1,n) scanf("%s",c[i]+1);
    forr(i,1,k) {
        int xx=x,yy=y;
        if(d==0) yy++;
        if(d==1) xx++;
        if(d==2) yy--;
        if(d==3) xx--;

        if(c[xx][yy]=='.' && 1<=xx&&xx<=n &&1<=yy&&yy<=m) {
            x=xx,y=yy;
            vis[x][y]=1;
            continue;
        } else {
            d=(d+1) % 4;
        }
    }

    int ans=0;
    forr(i,1,n) forr(j,1,m) if(vis[i][j]) ++ans;
    cout<<ans<<endl;


    return ;
}
int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int T; cin>>T;
    while(T--) sol() ;

    return 0;
}
