#include <bits/stdc++.h>
#define fin(str) freopen(str,"r",stdin)
#define fout(str) freopen(str,"w",stdout)
#define ll long long
using namespace std;

const int maxn=2e5+5;
const int maxA=1e6+5;
const ll inf=1e13;

int T;
int n,a[maxn];

inline void upd(ll &x,ll y) {x=max(x,y); }

struct segment{
    int l,r;
    ll maxx,tag;
}c[maxA<<2];
inline void pushup(int rt){
    c[rt].maxx=max(c[rt<<1].maxx,c[rt<<1|1].maxx);
}
inline void pushdown(int rt){
    if (c[rt].tag!=0){
        c[rt<<1].maxx+=c[rt].tag;
        c[rt<<1|1].maxx+=c[rt].tag;
        c[rt<<1].tag+=c[rt].tag;
        c[rt<<1|1].tag+=c[rt].tag;
        c[rt].tag=0;
    }
}
inline void build(int rt,int l,int r){
    if (rt==1) l++,r++;
    c[rt].l=l,c[rt].r=r;
    c[rt].tag=0;
    c[rt].maxx=-inf;
    if (l==r) return ;
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
}
inline ll query_max(int rt,int l,int r){
    if (rt==1) l++,r++;
    if (c[rt].l>r || c[rt].r<l) return -inf;
    if (c[rt].l>=l && c[rt].r<=r) return c[rt].maxx;
    pushdown(rt);
    return max(query_max(rt<<1,l,r),query_max(rt<<1|1,l,r));
}
inline void update_point(int rt,int pos,ll val){
    if (rt==1) pos++;
    if (c[rt].l>pos || c[rt].r<pos) return ;
    if (c[rt].l==pos && c[rt].r==pos){
        upd(c[rt].maxx,val);
        return ;
    }
    pushdown(rt);
    update_point(rt<<1,pos,val);
    update_point(rt<<1|1,pos,val);
    pushup(rt);
}
inline void update_add(ll val){
    c[1].maxx+=val;
    c[1].tag+=val;
}

inline void solve(){
    scanf("%d",&n);
    ll max_A=0;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),upd(max_A,a[i]);

    build(1,0,max_A);
    update_point(1,0,0);

    for (int i=1;i<=n;i++){
        ll val=-inf;
        upd(val,query_max(1,0,a[i]-1));
        if (a[i]+1<=max_A) upd(val,query_max(1,a[i]+1,max_A));
        upd(val,query_max(1,a[i],a[i])+a[i]);

        if (a[i]==a[i-1]) update_add(a[i]);
        update_point(1,a[i-1],val);
    }

    printf("%lld\n",query_max(1,0,max_A));
}

int main(){
    fin("color.in");
    fout("color.out");
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}
