#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+5;
const int V=1e6+2;
const LL INF=1e18;
int _;
int n;
LL a[N],sum[N],v[N],f[N];
namespace SegTree{
    LL tree[V<<2];
    int lc(int x){return x<<1;}
    int rc(int x){return x<<1|1;}
    void push_up(int rt){tree[rt]=max(tree[lc(rt)],tree[rc(rt)]);}
    void build(int rt,int l,int r){
        tree[rt]=-INF;
        if(l==r) return;
        int mid=(l+r)>>1;
        build(lc(rt),l,mid);
        build(rc(rt),mid+1,r);
    }
    void update(int rt,int l,int r,int x,LL v){
        if(l==r) return tree[rt]=max(tree[rt],v),void();
        int mid=(l+r)>>1;
        if(x<=mid) update(lc(rt),l,mid,x,v);
        if(x>mid) update(rc(rt),mid+1,r,x,v);
        push_up(rt);
    }
    LL query(int rt,int l,int r,int L,int R){
        if(L>R) return -INF;
        if(L<=l&&r<=R) return tree[rt];
        int mid=(l+r)>>1;
        LL ans=-INF;
        if(L<=mid) ans=max(ans,query(lc(rt),l,mid,L,R));
        if(R>mid) ans=max(ans,query(rc(rt),mid+1,r,L,R));
        return ans;
    }
}
using namespace SegTree;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&_);
    while(_--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        a[0]=1e6+1,a[n+1]=1e6+2;
        for(int i=1;i<=n;i++) v[i]=(a[i]==a[i+1]?a[i]:0),sum[i]=sum[i-1]+v[i-1];
        build(1,1,V);
        f[0]=0;
        update(1,1,V,a[0],f[0]-(sum[0]+v[0]));
        for(int i=1;i<=n;i++){
            f[i]=max(query(1,1,V,a[i+1],a[i+1])+a[i+1],max(query(1,1,V,1,a[i+1]-1),query(1,1,V,a[i+1]+1,V)))+sum[i];
            update(1,1,V,a[i],f[i]-(sum[i]+v[i]));
        }
        printf("%lld\n",f[n]);
    }
    return 0;
}
