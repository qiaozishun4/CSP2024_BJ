#include <bits/stdc++.h>
using namespace std;
template<typename T>
T read(T &x)
{
    bool flag=0;
    x=0;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar())
        if(ch=='-') flag=1;
    for(;isdigit(ch);ch=getchar())
        x=(x<<1)+(x<<3)+(ch^48);
    return flag?x=-x:x;
}
const int MAXN=1e5+3;
const int MAXL=1e6+3;
int T,n,m,L,V,p[MAXN];
struct Car
{
    int d,v,a;
} c[MAXN];
vector<Car> bkl;

inline bool check(const Car &cr,int pos)
{
    return cr.v*cr.v+2*cr.a*(pos-cr.d)>V*V;
}

int solve1()
{
    bkl.clear();
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(c[i].a>=0)
        {
            if(check(c[i],p[m]))
                bkl.push_back(c[i]),
                ++cnt;
        }
        else
        {
            int x=lower_bound(p+1,p+m+1,c[i].d)-p;
            if(p[x]<c[i].d) continue;
            if(2*c[i].a*(c[i].d-p[x])<c[i].v*c[i].v&&check(c[i],p[x]))
                bkl.push_back(c[i]),
                ++cnt;
        }
        //printf("i:%d cnt:%d\n",i,cnt);
    }
    return cnt;
}
vector<pair<int,int> > qy;
int analyis()
{
    int res=0;
    qy.clear();
    for(auto &&x:bkl)
    {
        if(x.a==0) qy.push_back({x.d,p[m]}),res=max(res,x.d);
        else if(x.a>0)
        {
            int s=(V*V-x.v*x.v)/(x.a<<1);
            if((V*V-x.v*x.v)%(x.a<<1)) ++s;
            qy.push_back({s,p[m]}),res=max(res,s);
        }
        else
        {
            int s=(x.v*x.v-V*V)/(-x.a*2);
            if((x.v*x.v-V*V)%(-x.a*2)) ++s;
            qy.push_back({x.d,s});
        }
    }
    return res;
}

int now;
struct Tag
{
    int t,tm;
    void update()
    {
        if(now>tm) tm=now,t=0;
    }
    Tag operator+(const Tag &rhs)
    {
        return {t+rhs.t,tm};
    }
} tag[MAXL<<3];
struct Info
{
    int mx,pos,tm;
    void update()
    {
        if(now>tm) tm=now,mx=0;
    }
    Info operator+(const Info &rhs)
    {
        if(!pos) return {rhs.mx,rhs.pos,tm};
        return {max(mx,rhs.mx),mx<rhs.mx?rhs.pos:pos,tm};
    }
    Info operator+(const Tag &rhs)
    {
        return {mx+rhs.t,pos,tm};
    }
} tr[MAXL<<3];
#define ls p<<1
#define rs p<<1|1
void pushdown(int p)
{
    tag[p].update();
    tr[ls].update(),tr[rs].update();
    tag[ls].update(),tag[rs].update();
    tag[ls]=tag[ls]+tag[p];
    tag[rs]=tag[rs]+tag[p];
    tr[ls]=tr[ls]+tag[p];
    tr[rs]=tr[rs]+tag[p];
    tag[p].t=0;
}
void build(int pp,int s,int t)
{
    if(s==t)
    {
        int x=*lower_bound(p+1,p+m+1,s);
        if(x==s) tr[pp].pos=s;
        return;
    }
    int mid=(s+t)>>1;
    build(pp<<1,s,mid);
    build(pp<<1|1,mid+1,t);
    tr[pp]=tr[pp<<1]+tr[pp<<1|1];
}
void modify(int p,int s,int t,int l,int r,int k=1)
{
    tr[p].update(),tag[p].update();
    if(l<=s&&t<=r)
    {
        tr[p]=tr[p]+Tag({k,now});
        tag[p]=tag[p]+Tag({k,now});
        return;
    }
    pushdown(p);
    int mid=(s+t)>>1;
    if(l<=mid) modify(ls,s,mid,l,r,k);
    if(r>mid) modify(rs,mid+1,t,l,r,k);
    tr[p]=tr[ls]+tr[rs];
}
Info query(int p,int s,int t,int l,int r)
{
    tr[p].update(),tag[p].update();
    if(l<=s&&t<=r) return tr[p];
    int mid=(s+t)>>1;
    Info res;
    if(l<=mid) res=query(ls,s,mid,l,r);
    if(r>mid) res=res+query(rs,mid+1,t,l,r);
    return res;
}

const int MAX=0x3f3f3f3f;

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    read(T);
    while(T--)
    {
        read(n),read(m),read(L),read(V);
        for(int i=1;i<=n;i++)
            read(c[i].d),read(c[i].v),read(c[i].a);
        for(int i=1;i<=m;i++)
            read(p[i]);
        printf("%d ",solve1());
        int mx=analyis();
        mx=lower_bound(p+1,p+n+1,mx)-p;
        int l=L;
        build(1,0,l);
        for(auto &&x:qy)
        {
            if(x.first<=mx&&x.second>=mx)
                continue;
            modify(1,0,l,x.first,x.second);
        }
        int cnt=0;
        for(auto &&x:qy)
        {
            if(x.first<=mx&&x.second>=mx)
                continue;
            auto tmp=query(1,0,l,x.first,x.second);
            if(tmp.mx>=MAX) continue;
            ++cnt;
            modify(1,0,l,tmp.pos,tmp.pos,MAX);
        }
        printf("%d\n",cnt);
    }
    return 0;
}
