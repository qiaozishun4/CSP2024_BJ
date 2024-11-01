#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int AMAX=1000000;
int t,n,a[200005];
ll f[200005];
struct Node{
    ll lazy,mx;
};
Node tr[(AMAX<<2)+5];
void pushdown(int x){
    tr[x<<1].lazy+=tr[x].lazy,tr[x<<1].mx+=tr[x].lazy;
    tr[x<<1|1].lazy+=tr[x].lazy,tr[x<<1|1].mx+=tr[x].lazy;
    tr[x].lazy=0;
}
void pushup(int x){
    tr[x].mx=max(tr[x<<1].mx,tr[x<<1|1].mx);
}
void build(int x,int l,int r){
    if(l==r){
        tr[x].mx=tr[x].lazy=0;
        return;
    }
    pushdown(x);
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
void add(int x,int l,int r,int ql,int qr,ll a){
    // printf("add %d %d %d %d %d %lld\n",x,l,r,ql,qr,a);
    if(ql<=l&&r<=qr){
        tr[x].lazy+=a,tr[x].mx+=a;
        return;
    }
    pushdown(x);
    int mid=(l+r)>>1;
    if(ql<=mid) add(x<<1,l,mid,ql,qr,a);
    if(qr>mid) add(x<<1|1,mid+1,r,ql,qr,a);
    pushup(x);
}
void upd(int x,int l,int r,int q,ll a){
    // printf("upd %d %d %d %d %lld\n",x,l,r,q,a);
    if(l==r){
        tr[x].mx=max(tr[x].mx,a);
        return;
    }
    pushdown(x);
    int mid=(l+r)>>1;
    if(q<=mid) upd(x<<1,l,mid,q,a);
    if(q>mid) upd(x<<1|1,mid+1,r,q,a);
    pushup(x);
}
ll query(int x,int l,int r,int q){
    if(l==r) return tr[x].mx;
    pushdown(x);
    int mid=(l+r)>>1;
    if(q<=mid) return query(x<<1,l,mid,q);
    return query(x<<1|1,mid+1,r,q);
}
int main(){
    #ifndef JZQ
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    #endif
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        build(1,0,AMAX);
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            // printf("%d %d ",query(1,0,AMAX,0),query(1,0,AMAX,a[i]));
            f[i]=max(query(1,0,AMAX,0),query(1,0,AMAX,a[i]));
            add(1,0,AMAX,0,AMAX,(a[i]==a[i-1]?a[i]:0));
            upd(1,0,AMAX,0,f[i]);
            if(a[i-1]) upd(1,0,AMAX,a[i-1],f[i]+a[i-1]);
            // printf("%d\n",f[i]);
        }
        printf("%lld\n",query(1,0,AMAX,0));
    }
    return 0;
}