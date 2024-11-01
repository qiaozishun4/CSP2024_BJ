#include<cstdio>
#include<algorithm>
char buf[1<<21],*p1=buf,*p2=buf;
inline char Getc(){if(p1==p2){p2=(p1=buf)+fread(buf,1,1<<21,stdin);if(p1==p2) return EOF;}return *p1++;}
inline int rd()
{
    static char ch;
    bool flag=false;
    int x=0;
    while(ch=Getc(),(ch<'0'||ch>'9')&&ch!='-');
    if(ch!='-') x=ch^'0';
    else flag=true;
    while(ch=Getc(),'0'<=ch&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');
    return flag?(-x):x;
}
typedef long long ll;
const int N=100010;
int d[N],v[N],a[N],p[N];
int n,m,L,V;
inline int solve0(ll x)
{
    int L=1,R=m;
    if(x>p[m]) return -1;
    while(L<R)
    {
        int mid=(L+R)>>1;
        if(p[mid]>=x) R=mid;
        else L=mid+1;
    }
    return L;
}
inline ll calc(int i)
{
    ll x=((ll)v[i]*v[i]-(ll)V*V),y=(-a[i])*2;
    return x/y+((x%y)?1:0)+d[i];
}
inline int solve1(ll x)
{
    int L=1,R=m;
    if(p[1]>=x) return -1;
    while(L<R)
    {
        int mid=(L+R+1)>>1;
        if(p[mid]<x) L=mid;
        else R=mid-1;
    }
    return L;
}
struct Node
{
    int l,r;
    inline bool operator < (const Node &x)const
    {
        if(r!=x.r) return r<x.r;
        return l>x.l;
    }
}f[N];
int k;
inline void Add(int x,int y){++k,f[k].l=x,f[k].r=y;}
int c[N];
inline void Modify(int x){for(;x<=m;x+=x&(-x)) ++c[x];}
inline int Query(int x){int r=0;for(;x;x-=x&(-x)) r+=c[x];return r;}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T=rd();
    while(T--)
    {
        n=rd(),m=rd(),L=rd(),V=rd();
        for(int i=1;i<=n;++i) d[i]=rd(),v[i]=rd(),a[i]=rd();
        for(int i=1;i<=m;++i) p[i]=rd();
        k=0;
        for(int i=1;i<=n;++i)
        {
            int pos=solve0(d[i]);
            if(pos==-1) continue;
            if(a[i]==0){if(v[i]>V) Add(pos,m);}
            else if(a[i]>0)
            {
                if(v[i]>V) Add(pos,m);
                else
                {
                    int tmp=solve0(((ll)V*V-(ll)v[i]*v[i])/(a[i]*2)+1+d[i]);
                    if(tmp!=-1) Add(tmp,m);
                }
            }
            else if(a[i]<0)
            {
                if(v[i]<=V) continue;
                int tmp=solve1(calc(i));
                if(tmp!=-1&&pos<=tmp) Add(pos,tmp);
            }
        }
        std::sort(f+1,f+k+1);
        for(int i=1;i<=m;++i) c[i]=0;
        int ans=0;
        for(int i=1;i<=k;++i) if(Query(f[i].r)==Query(f[i].l-1)) Modify(f[i].r),++ans;
        printf("%d %d\n",k,m-ans);
    }
    return 0;
}
