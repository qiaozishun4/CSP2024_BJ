#include<bits/stdc++.h>
#define rep(i,S,T) for(int i=S;i<=T;++i)
#define per(i,T,S) for(int i=T;i>=S;--i)
using namespace std;
template<typename T>
inline void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}
const int N=2e3+10;
int T;
int n,m,k,a[N][N],vis[N][N];
int sx,sy,d;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void solve(){
    read(n);read(m);read(k);
    read(sx);read(sy);read(d);
    rep(i,1,n) rep(j,1,m){
        vis[i][j]=0;
        char c;cin>>c;
        if(c=='x') a[i][j]=1;
        else a[i][j]=0;
    }
    int dep=0,x=sx,y=sy,f=d;
    while(1){
        if(dep>k) break;
        vis[x][y]=1;
        int tx=x+dx[f],ty=y+dy[f];
        if(tx<=0||ty<=0||tx>n||ty>m||a[tx][ty]==1){
            f=(f+1)%4;
        }
        else{
            x=tx;y=ty;
        }
        dep++;
    }
    int ans=0;
    rep(i,1,n) rep(j,1,m) ans+=vis[i][j];
    printf("%d\n",ans);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    read(T);while(T--) solve();
    return 0;
}
