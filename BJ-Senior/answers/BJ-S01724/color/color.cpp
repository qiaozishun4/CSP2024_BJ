#include <bits/stdc++.h>
#define int long long
#define ls u<<1
#define rs u<<1|1
using namespace std;
int T,n;
namespace solve1{
    const int N=2005;
    int a[N];
    int f[N][N];
    int ans=0;
    void main(){
        memset(f,0,sizeof(f)); ans=0;
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(int i=2;i<=n;i++){
            int mx=0;
            for(int j=0;j<i-1;j++){
                f[i][j] = f[i-1][j]+a[i]*(a[i]==a[i-1]);
                mx = max(f[i-1][j]+a[i]*(a[i]==a[j]),mx);
            }
            f[i][i-1] = mx;
        }
        for(int j=0;j<=n-1;j++)
            ans = max(f[n][j],ans);
        printf("%lld\n",ans);
    }
}
namespace solve2{
    const int N=2e5+5,M=1e6+5;
    const int inf=1e18;
    int a[N];
    int mx[M<<2],tag[M<<2];
    bool flg[M];
    int b[M],tot;
    int p[M];
    void init(){
        memset(flg,0,sizeof(flg));
        tot=0;
    }
    void pushdown(int u){
        mx[ls]+=tag[u]; tag[ls]+=tag[u];
        mx[rs]+=tag[u]; tag[rs]+=tag[u];
        tag[u]=0;
    }
    void build(int u,int l,int r){
        tag[u]=0; mx[u]=-inf;
        if(l==r) return;
        int mid = (l+r)>>1;
        build(ls,l,mid); build(rs,mid+1,r);
    }
    void update(int u,int l,int r,int ql,int qr,int x){
        if(ql>qr) return;
        if(ql<=l && r<=qr){
            mx[u]+=x; tag[u]+=x;
            return;
        }
        if(tag[u]) pushdown(u);
        int mid = (l+r)>>1;
        if(ql<=mid) update(ls,l,mid,ql,qr,x);
        if(qr>mid) update(rs,mid+1,r,ql,qr,x);
        mx[u] = max(mx[ls],mx[rs]);
    }
    void update2(int u,int l,int r,int p,int x){
        if(l==r) {mx[u]=max(x,mx[u]); return;}
        if(tag[u]) pushdown(u);
        int mid = (l+r)>>1;
        if(p<=mid) update2(ls,l,mid,p,x);
        else update2(rs,mid+1,r,p,x);
        mx[u] = max(mx[ls],mx[rs]);
    }
    int query(int u,int l,int r,int p){
        if(l==r) return mx[u];
        if(tag[u]) pushdown(u);
        int mid = (l+r)>>1;
        if(p<=mid) return query(ls,l,mid,p);
        else return query(rs,mid+1,r,p);
    }
    void main(){
        init();
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            if(!flg[a[i]]){
                b[++tot] = a[i];
                p[a[i]] = tot;
                flg[a[i]] = 1;
            }
        }
        build(1,1,tot);
        update2(1,1,tot,p[a[1]],0);
        for(int i=2,now=1;i<=n;i++){
            int res = max(query(1,1,tot,p[a[i]])+a[i],mx[1]);
            if(a[i]==a[i-1]) update(1,1,tot,1,now,a[i]);
            update2(1,1,tot,p[a[i-1]],res);
            if(a[i]==b[now+1]) now++;
        }
        printf("%lld\n",mx[1]);
    }
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        // solve2::main();
        if(n<=2000) solve1::main();
        else solve2::main();
    }
    return 0;
}