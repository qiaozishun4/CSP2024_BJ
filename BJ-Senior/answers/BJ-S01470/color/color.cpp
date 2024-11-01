#include<bits/stdc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r) for(int i=(l);i>=(r);--i)
#define pi pair<int,int>
#define p1 first
#define p2 second
#define m_p make_pair
#define p_b push_back
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
inline ll read(){
    ll x=0;short t=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*t;
}
int n,a[maxn],b[maxn];
struct SegTree {
    struct nd {
        ll mx;
    }d[maxn<<2];
    #define ls(p) (p<<1)
    #define rs(p) (p<<1|1)
    #define mx(p) d[p].mx
    void pu(int p){mx(p)=max(mx(ls(p)),mx(rs(p)));}
    void bd(int l,int r,int p){
        mx(p)=-1e18;
        if(l==r)return;
        int mid=l+r>>1;
        bd(l,mid,ls(p)),bd(mid+1,r,rs(p));
    }void modify(int l,int s,int t,int p,ll x){
        mx(p)=max(mx(p),x);
        if(s==t)return;
        int mid=s+t>>1;
        if(l<=mid)modify(l,s,mid,ls(p),x);else modify(l,mid+1,t,rs(p),x);
    }ll qry(int l,int s,int t,int p){
        if(s==t)return mx(p);
        int mid=s+t>>1;
        if(l<=mid)return qry(l,s,mid,ls(p));return qry(l,mid+1,t,rs(p));
    }
}T;
void slv(){
    n=read();up(i,1,n)a[i]=read(),b[i]=a[i];
    sort(b+1,b+n+1);int m=unique(b+1,b+n+1)-b-1;
    up(i,1,n)a[i]=lower_bound(b+1,b+m+1,a[i])-b;
    T.bd(0,n,1),T.modify(0,0,n,1,0);
    ll add=0;
    up(i,0,n-1){
        ll val=max(T.qry(a[i+1],0,n,1)+b[a[i+1]],T.mx(1))+add;
        if(a[i]==a[i+1])add+=b[a[i]];
        T.modify(a[i],0,n,1,val-add);
    }printf("%lld\n",T.mx(1)+add);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t=read();while(t--)slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}