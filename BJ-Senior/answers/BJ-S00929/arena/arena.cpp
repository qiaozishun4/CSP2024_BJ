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
const int N=5e5+5;
bool win[N];
int a[N];
int ax[N];
int n,m,c[N];
int k,up;
int id[N];
void dfs1(int x,int l,int r,int dep)
{
    id[x]=-1;
    if(l==r) 
    {
        if(r<=n) id[x]=r;
        return ;
    }
    int mid=l+r>>1;
    dfs1(x<<1,l,mid,dep-1);
    dfs1(x<<1|1,mid+1,r,dep-1);
    if(r<=n) id[x]=win[x]?(a[id[x<<1]]>=dep?id[x<<1]:id[x<<1|1]):(a[id[x<<1|1]]>=dep?id[x<<1|1]:id[x<<1]);
}
bitset<N> merge(bitset<N> tmp1,bitset<N> tmp2,int dep)
{
    if(tmp1._Find_first()>=dep) return tmp1;
    return ((tmp1>>dep)<<dep)|tmp2;
}
bitset<N> dfs2(int x,int l,int r,int dep,int n)
{
    // cout<<x<<" "<<l<<" "<<r<<" "<<dep<<" "<<n<<endl; 
    if(l>n)
    {
        bitset<N> ans;
        ans.reset(0);
        for(int i=l;i<=r;i++) ans[i]=1;
        return ans;
    }
    if(r<=n)
    {
        bitset<N> ans;
        ans.reset(0);
        ans[id[x]]=1;
        return ans;
    }
    int mid=l+r>>1;
    bitset<N> tmp1,tmp2;
    tmp1=dfs2(x<<1,l,mid,dep-1,n);
    tmp2=dfs2(x<<1|1,mid+1,r,dep-1,n);
    return win[x]?merge(tmp1,tmp2,dep):merge(tmp2,tmp1,dep);
}
void solve()
{
    dfs1(1,1,up,k-1);
    __int128 ans=0;
    for(int i=1;i<=m;i++)
    {
        int x=1,l=1,r=up,cnt=0;
        while((l+r>>1)>c[i])
        {
            x=x<<1;
            r=(l+r)>>1;
            cnt++;
        }
        bitset<N> tmp=dfs2(x,l,r,k-1-cnt,c[i]);
        int pos=tmp._Find_first();
        ll g=0;
        while(pos!=tmp.size())
        {
            g+=pos;
            pos=tmp._Find_next(pos);
        }
        ans^=(__int128)1*i*g;
    }
    writeln(ans);
}
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    read(n);read(m);
    k=ceill(log2(n));
    up=1<<k;
    k++;
    for(int i=1;i<=n;i++) read(ax[i]);
    for(int i=1;i<=m;i++) read(c[i]);
    for(int i=up-1;i>=1;i--)
    {
        char ch;
        cin>>ch;
        win[i]=ch-'0';
    }
    int T;
    read(T);
    while(T--)
    {
        int x[10];
        for(int i=0;i<4;i++) read(x[i]);
        for(int i=1;i<=n;i++) a[i]=(ax[i]^x[i%4]);
        solve();
    }
    return 0;
}
