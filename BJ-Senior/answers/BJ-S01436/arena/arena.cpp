#include <bits/stdc++.h>
#define il inline
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
il int read(){
    int x=0,c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=x*10+c-48,c=getchar();
    return x;
}
const int N=1e5+5,M=(1<<18)+5,inf=1e9;
int CK;
int T,n,m,A[N],a[N],b[N],X[4],lg[M],LG[M];char s[19][M];int cnt;
int f[M],ck[M];
il void init(){
    for(int i=0;i<4;++i) X[i]=read();
    for(int i=1;i<=n;++i) a[i]=(A[i]^X[i&3]);
}
int cur,k;
void dfs(int x){
    if(x>=(1<<k)){
        int y=x-(1<<k)+1;
        if(y<=cur) f[x]=(1<<min(a[y],k));
        else f[x]=(1<<(k+1))-1;
        ck[x]=(f[x]&1);
        return ;
    }
    int y=(x<<1),z=(x<<1|1),u,v,w;dfs(y),dfs(z);
    u=k-lg[x];
    if(s[u][x-(1<<lg[x])]=='0') ;else swap(y,z);
    f[x]=((f[y]>>u)<<u);
    v=(f[y]&((1<<u)-1));
    if(v) f[x]|=f[z];
    if(f[x]&((1<<(u+1))-1)) ck[x]=1;
    else ck[x]=0;
}
il ll calc(int len){
    int x,y,z,u,v,w,ret=0ll,cc;k=LG[len];
    cur=len;
    //dfs(1);
    for(int x=(1<<k);x<(1<<(k+1));++x){
        int y=x-(1<<k)+1;
        if(y<=cur) f[x]=(1<<min(a[y],k));
        else f[x]=(1<<(k+1))-1;
        ck[x]=(f[x]&1);
    }
    for(int x=(1<<k)-1;x;--x){
        int y=(x<<1),z=(x<<1|1),u,v,w;//dfs(y),dfs(z);
        u=k-lg[x];
        if(s[u][x-(1<<lg[x])]=='0') ;else swap(y,z);
        f[x]=((f[y]>>u)<<u);
        v=(f[y]&((1<<u)-1));
        if(v) f[x]|=f[z];
        if(f[x]&((1<<(u+1))-1)) ck[x]=1;
        else ck[x]=0;
    }
    for(int i=1;i<=len;++i){
        cc=1,x=(1<<k)+i-1;
        for(int j=1;j<=k;++j){
            y=(x>>(j-1)),z=(y>>1)-(1<<(k-j));
            if(y&1) w=(s[j][z]=='1');
            else w=(s[j][z]=='0');
            if(w) cc&=(a[i]>=j);
            else cc&=ck[y^1];
            if(!cc) break;
        }
        if(cc) ret+=1ll*i;
    }
    for(int i=len+1;i<=(1<<k);++i){
        cc=1,x=(1<<k)+i-1;
        for(int j=1;j<=k;++j){
            y=(x>>(j-1)),z=(y>>1)-(1<<(k-j));
            if(y&1) w=(s[j][z]=='1');
            else w=(s[j][z]=='0');
            if(w) ;
            else cc&=ck[y^1];
            if(!cc) break;
        }
        if(cc) ret+=1ll*i;
    }
    return ret;
}
ll ans[M];int vis[M];
il void solve(){
    init();
    ll ret=0ll;
    for(int i=1;i<=n;++i) if(vis[i]) ans[i]=calc(i);
    for(int i=1;i<=m;++i) ret^=(1ll*i*ans[b[i]]);
    printf("%lld\n",ret);
}
int x,y,z,u,v,w;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%d%d",&n,&m);
    x=1;while(x<n) x<<=1;x<<=1;
    for(int i=2;i<=x;++i) lg[i]=lg[i>>1]+1;
    for(int i=1;i<=x;++i) LG[i]=lg[i]+((i&-i)!=i);x=0;
    for(int i=1;i<=n;++i) A[i]=read();
    for(int i=1;i<=m;++i) b[i]=read(),vis[b[i]]=1;
    for(int i=1;i<=LG[n];++i) scanf("%s",s[i]);
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}
