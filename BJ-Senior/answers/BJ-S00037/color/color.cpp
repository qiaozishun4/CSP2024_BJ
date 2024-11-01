bool bg;
#include<bits/stdc++.h>
using namespace std;
#define rps(i, b, e) for(int i=(b);i<=(e);i++)
#define prs(i, e, b) for(int i=(e);i>=(b);i--)
#define rpg(i, g, x) for(int i=g.head[x];i;i=g.e[i].nxt)
#define mem(a, x) memset(a, x, sizeof(a))
#define opf(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
namespace cszhpdx {
template<class T>
void read(T &x) {
    x=0;
    bool f=false;
    char c=getchar();
    while(!isdigit(c))f|=(c=='-'), c=getchar();
    while(isdigit(c))x=x*10+(c-'0'), c=getchar();
    if(f)x=-x;
}
const int NR=2e5+10, MR=8e5+10, VR=1e6+10;
typedef long long LL;
int ys[VR], ysct;
LL f[NR], del;
vector<int>va[NR];
inline LL max(LL x, LL y) {
    return (x>y ? x : y);
}
int rt[NR], cnt, lc[MR], rc[MR], fa[MR], dy[NR], dy0[NR];
LL mx[MR];
    bool ed;
inline void pushup(int x) {
    mx[x]=max(mx[lc[x]], mx[rc[x]]);
}
int build(int k, int l, int r) {
    int x=++cnt;
    if(l==r) {
        mx[x]=f[va[k][l-1]];
        dy[va[k][l-1]]=x;
        if(k==0)dy0[va[k][l-1]]=x;
        return x;
    }
    int mid=(l+r)/2;
    lc[x]=build(k, l, mid);
    rc[x]=build(k, mid+1, r);
    fa[lc[x]]=fa[rc[x]]=x;
    pushup(x);
    return x;
}
void updt(int x, LL v) {
    mx[x]=v;
    for(int p=fa[x];p>0;p=fa[p])pushup(p);
}
void upd(int x, LL v) {
    // printf("x=%d v=%lld\n", x, v);
    f[x]=v;
    updt(dy[x], v);
    updt(dy0[x], v);
}
LL gt(LL x) {
    return f[x]+del;
}
void add(LL v) {
    del+=v;
}
LL n, a[NR];
void build() {
    rps(i, 0, n)va[0].push_back(i);
    rt[0]=build(0, 1, n+1);
    rps(i, 0, n) {
        if(ys[a[i]]==0)ys[a[i]]=++ysct;
        va[ys[a[i]]].push_back(i);
    }
    rps(i, 1, ysct)rt[i]=build(i, 1, va[i].size());
}

void work() {
    del=0;
    read(n);
    rps(i, 1, n)read(a[i]);
    a[0]=a[n+1]=0;
    rps(i, 0, n)f[i]=-1e18;
    LL INF=f[0];
    //begin from f[1][0]
    f[0]=0;
    build();
    rps(i, 1, n-1) {
        LL w=a[i]*(a[i]==a[i+1]);
        LL xq=mx[rt[0]], xi=mx[rt[ys[a[i+1]]]];
        LL tmp=max(xq, xi+a[i+1])+del;
        add(a[i]*(a[i]==a[i+1]));
        // printf("tmp=%lld xq=%lld xi=%lld a[i+1]=%lld\n", tmp+del, xq+del, xi+del, a[i+1]);
        upd(i, tmp-del);
        // rps(j, 0, i)printf("%lld ", f[j]+del);printf("|f[%d]\n", i+1);
        // rps(j, 0, ysct)printf("%lld ", mx[rt[j]]+del);printf("|mx[rt[j]]\n");
    }
    LL ans=0;
    rps(i, 0, n-1)ans=max(ans, f[i]+del);
    printf("%lld\n", ans);
    rps(i, 1, n)ys[a[i]]=0;
    rps(i, 0, cnt)fa[i]=lc[i]=mx[i]=rc[i]=0;
    cnt=0;
    rps(i, 0, ysct)va[i].clear();
    ysct=0;
}
int main() {
    opf("color");
    int T;read(T);
    while(T--)work();
    // cerr<<((&ed)-(&bg))<<endl;
    return 0;
}
}
int main() {
    return cszhpdx::main();
}