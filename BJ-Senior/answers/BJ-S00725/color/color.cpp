#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=8e5+5;
struct Pair{
    ll a[2];
    inline const Pair Max(const Pair &t) const {
        return (Pair){max(a[0], t.a[0]), max(a[1], t.a[1])};
    }
    inline const Pair operator +(const Pair &t) const {
        return (Pair){a[0] + t.a[0], a[1] + t.a[1]};
    }
    inline const Pair operator +(const int &k) const {
        return (Pair){a[0] + k, a[1] + k};
    }
};
struct SegTree{
    Pair tag[N],mx[N];
    inline int ls(int p){return p<<1;}
    inline int rs(int p){return p<<1|1;}
    inline void pushUp(int p){
        mx[p] = mx[ls(p)].Max(mx[rs(p)]);
    }
    inline void pushDown(int p){
        if (tag[p].a[0] && tag[p].a[1]) {
            tag[ls(p)] = tag[ls(p)] + tag[p];
            tag[rs(p)] = tag[rs(p)] + tag[p];
            mx[ls(p)] = mx[ls(p)] + tag[p];
            mx[rs(p)] = mx[rs(p)] + tag[p];
            tag[p]={0,0};
        }
    }
    inline void update(int p,int l,int r,int x,Pair k) {
        if(l==r) {
            mx[p] = mx[p].Max(k);
            return;
        }
        pushDown(p);
        int mid=l+r>>1;
        if (x<=mid)
            update(ls(p),l,mid,x,k);
        else
            update(rs(p),mid+1,r,x,k);
        pushUp(p);
    }
    inline void add(int p,int l,int r,int x,Pair k) {
        if(l==r) {
            mx[p] = mx[p] + k;
            return;
        }
        pushDown(p);
        int mid=l+r>>1;
        if (x<=mid)
            add(ls(p),l,mid,x,k);
        else
            add(rs(p),mid+1,r,x,k);
        pushUp(p);
    }
}seg;
int T,n;
ll a[N],buc[N];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        memset(seg.tag,0,sizeof(seg.tag));
        memset(seg.mx,0,sizeof(seg.mx));
        seg.tag[1]={(ll)-1e18,(ll)-1e18};
        cin>>n;
        seg.update(1,0,n,0,{0,0});
        for(int i=1;i<=n;i++)
            cin>>a[i],buc[i]=a[i];
        sort(buc+1,buc+1+n);
        for(int i=1;i<=n;i++)
            a[i]=lower_bound(buc+1,buc+1+n,a[i])-buc;
        for(int i=1;i<=n;i++) {
            seg.add(1,0,n,a[i],{buc[a[i]], buc[a[i]]});
            ll k0 = seg.mx[1].a[0], k1 = seg.mx[1].a[1];
            seg.add(1,0,n,a[i],{-buc[a[i]],-buc[a[i]]});
            seg.tag[1] = seg.tag[1] + (a[i] == a[i-1]) * buc[a[i]];
            seg.mx[1] = seg.mx[1] + (a[i] == a[i-1]) * buc[a[i]];
            seg.update(1,0,n,a[i-1],{k0,k1});
        }
        cout << max(seg.mx[1].a[0], seg.mx[1].a[1]) << '\n';
    }
    return 0;
}
