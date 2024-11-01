#include <bits/stdc++.h>
#define pow power
#define ll long long
#define ull unsigned long long
using namespace std;
template <typename T>void read(T &x)
{
    x=0;
    int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+c-'0';
    x*=f;
}
template <typename T>void write(T x)
{
    if(x<0)
    {
        putchar('-');
        write(-x);
        return ;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
template <typename T>void writeln(T x)
{
    write(x);
    putchar('\n');
}    
const int N=1e6+5;
const ll inf=LONG_LONG_MAX;
int a[N];
struct SEGMENT_TREE
{
    struct node
    {
        int l,r;
        ll mx;
        ll tag;
    } tr[N<<2];
    void pushup(int x)
    {
        tr[x].mx=max(tr[x<<1].mx,tr[x<<1|1].mx);
    }
    void push(int x,ll k)
    {
        tr[x].tag+=k;
        tr[x].mx+=k;
    }
    void pushdown(int x)
    {
        if(tr[x].tag)
        {
            push(x<<1,tr[x].tag);
            push(x<<1|1,tr[x].tag);
            tr[x].tag=0;
        }
    }
    void add(int x,int l,int r,ll k)
    {
        if(l<=tr[x].l&&tr[x].r<=r) 
        {
            push(x,k);
            return ;
        }
        pushdown(x);
        int mid=tr[x].l+tr[x].r>>1;
        if(l<=mid) add(x<<1,l,r,k);
        if(mid+1<=r) add(x<<1|1,l,r,k);
        pushup(x);
    }
    void insert(int x,int pos,ll k)
    {
        if(tr[x].l==tr[x].r)
        {
            tr[x].mx=max(tr[x].mx,k);
            return ;
        }
        pushdown(x);
        int mid=tr[x].l+tr[x].r>>1;
        if(pos<=mid) insert(x<<1,pos,k);
        else insert(x<<1|1,pos,k);
        pushup(x);
    }
    void build(int x,int l,int r)
    {
        tr[x].l=l;
        tr[x].r=r;
        tr[x].mx=-inf;
        tr[x].tag=0;
        if(l==r) return ;
        int mid=l+r>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        pushup(x);
    }
    ll query(int x,int l,int r)
    {
        if(l<=tr[x].l&&tr[x].r<=r) return tr[x].mx;
        pushdown(x);
        int mid=tr[x].l+tr[x].r>>1;
        ll ans=-inf;
        if(l<=mid) ans=max(ans,query(x<<1,l,r));
        if(mid+1<=r) ans=max(ans,query(x<<1|1,l,r));
        pushup(x);
        return ans;
    }
} tr;
int up=1000000;
int t[N],len;
int get(int x)
{
    return lower_bound(t+1,t+len+1,x)-t;
}
void solve()
{
    int n;
    read(n);
    len=0;
    for(int i=1;i<=n;i++) read(a[i]),t[++len]=a[i];
    sort(t+1,t+len+1);
    len=unique(t+1,t+len+1)-t-1;
    tr.build(1,1,len);
    ll holder=0;
    for(int i=2;i<=n;i++)
    {
        ll tmp=max(max(holder,tr.query(1,1,len)),a[i]+tr.query(1,get(a[i]),get(a[i])));
        // cout<<"*"<<tmp<<endl;
        if(a[i]==a[i-1]) tr.add(1,1,len,a[i]),holder+=a[i];
        tr.insert(1,get(a[i-1]),tmp);
    }
    writeln(tr.query(1,1,up));
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    read(T);
    while(T--) solve();
    return 0;
}