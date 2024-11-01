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
const int N=2e5+5;
int n,m,L,V;
struct over
{
    int l,r;
    bool operator<(const over hh)const
    {
        if(r==hh.r) return l>hh.l;
        return r<hh.r;
    }
} a[N],p[N];
int lena,lenp;
int g[N];
namespace PROB2
{
    over z[N];
    int lenz;
    void solve()
    {
        if(!lenp)
        {
            writeln(m);
            return ;
        }
        sort(p+1,p+lenp+1);
        lenz=1;
        z[1]=p[1];
        for(int i=2;i<=lenp;i++)
            if(z[lenz].l<p[i].l)
                z[++lenz]=p[i];
        int ans=0;
        int pos=0;
        for(int i=1;i<=lenz;i++)
        {
            // cout<<"*"<<z[i].l<<" "<<z[i].r<<endl;
            if(z[i].l>g[pos])
            {
                while(g[pos]<=z[i].r&&pos<=m) pos++;
                pos--;
                ans++;
            }
        }
        writeln(m-ans);
    }
}
void clear()
{
    lena=lenp=0;
}
void push(int d,int v0,int a0)
{
    if(a0<0)
    {
        if(v0>V)
        {
            ll l=d,r=(-1ll*V*V+1ll*v0*v0+-2*a0-1)/(-2*a0)-1;
            if(l<=min(1ll*L,d+r)) a[++lena]=(over){l,min(1ll*L,d+r)};
        }
    }
    else if(a0==0)
    {
        if(v0>V) a[++lena]=(over){d,L};
    }
    else
    {
        if(v0>V) a[++lena]=(over){d,L};
        else
        {
            ll r=L,l=(1ll*V*V-1ll*v0*v0)/(2*a0)+1;
            if(d+l<=r) a[++lena]=(over){d+l,r};
        }
        
    }
}
void solve()
{
    g[0]=-1;
    clear();
    read(n);read(m);read(L);read(V);
    for(int i=1;i<=n;i++)
    {
        int d,v,a;
        read(d);read(v);read(a);
        push(d,v,a);
    }
    // for(int i=1;i<=lena;i++) cout<<a[i].l<<" "<<a[i].r<<endl;
    for(int i=1;i<=m;i++) read(g[i]);
    sort(g+1,g+m+1);
    int ans=0;
    for(int i=1;i<=lena;i++)
    {
        int pos=lower_bound(g+1,g+m+1,a[i].l)-g;
        // cout<<"*"<<a[i].l<<" "<<g[pos]<<" "<<a[i].r<<endl;
        if(g[pos]<=a[i].r&&pos<=m)
        {
            ans++;
            p[++lenp]=a[i];
        }
    }
    write(ans);
    putchar(' ');
    PROB2::solve();
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    read(T);
    while(T--) solve();
    return 0;
}
