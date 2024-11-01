#include<iostream>
#include<cassert>
#include<algorithm>
using namespace std;

typedef int ll;
const ll MXN=1e5+10;
const ll MXL=1e6+10;
const ll INF=1e9+7;
struct node {signed l,r;ll s,mn;};
struct tree
{
    node t[MXL<<2];

    inline void merg(int o) {t[o].s=t[2*o].s+t[2*o+1].s;t[o].mn=min(t[2*o].mn,t[2*o+1].mn);}

    inline void build(int o,int l,int r)
    {
        t[o]={l,r,0,INF};
        if(l==r) return ;
        ll mid=(l+r)>>1;
        build(2*o,l,mid);
        build(2*o+1,mid+1,r);
    }

    inline void upd(int o,int x,ll v,ll typ)
    {
        if(t[o].l==t[o].r) 
        {
            if(typ==1) t[o].s+=v;
            if(typ==2) t[o].mn=min(t[o].mn,v);
            return ;
        }
        ll mid=(t[o].l+t[o].r)>>1;
        if(x<=mid) upd(2*o,x,v,typ);
        else upd(2*o+1,x,v,typ);
        merg(o);
    }

    inline ll qry(int o,int ql,int qr,ll typ)
    {
        if(ql<=t[o].l&&t[o].r<=qr) 
        {
            if(typ==1) return t[o].s;
            if(typ==2) return t[o].mn;
        }
        ll mid=(t[o].l+t[o].r)>>1,ret=0;
        if(typ==1)
        {
            if(ql<=mid) ret+=qry(2*o,ql,qr,typ);
            if(mid<qr) ret+=qry(2*o+1,ql,qr,typ);
        }
        if(typ==2)
        {
            ret=INF;
            if(ql<=mid) ret=min(ret,qry(2*o,ql,qr,typ));
            if(mid<qr) ret=min(ret,qry(2*o+1,ql,qr,typ));
        }
        return ret;
    }
}t1,t2;

ll d[MXN],v[MXN],a[MXN],pos[MXN];
struct pll {ll L,R;}xd[MXN];
ll mceil(ll a,ll b) {return (a+b-1)/b;}
ll mfloor(ll a,ll b) {return a/b;}
inline bool cmp(pll a,pll b) 
{
    // cout<<a.L<<' '<<a.R<<' '<<b.L<<' '<<b.R<<endl;
    if(a.L==b.L) return a.R<b.R;
    return a.L>b.L; 
}
inline bool invcmp(pll a,pll b)
{
    if(a.L==b.L) return (a.R>b.R);
    return (a.L<b.L); 
}

void Solve()
{
    ll n,m,ln,V;cin>>n>>m>>ln>>V;
    t1.build(1,1,ln);ll k=0;
    for(ll i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
    for(ll i=1;i<=m;i++)
    {
        cin>>pos[i];
        t1.upd(1,pos[i],1,1);
    }
    for(ll i=1;i<=n;i++)
    {
        ll L,R;
        if(a[i]>0)
        {
            if(v[i]>V) L=d[i],R=ln;
            else if(v[i]<V) 
            {
                L=mceil(V*V-v[i]*v[i]+1,2*a[i])+d[i],R=ln;
                if(L>R) L=-1,R=-1;
            }
            else if(v[i]==V)
            {
                L=d[i]+1,R=ln;
                if(L>R) L=-1,R=-1;
            }
        }
        else if(a[i]==0)
        {
            if(v[i]<=V) L=-1,R=-1;
            else if(v[i]>V) L=d[i],R=ln;
        }
        else if(a[i]<0)
        {
            if(v[i]>V) L=d[i],R=min(mfloor(V*V-v[i]*v[i]+1,2*a[i])+d[i],ln);
            else if(v[i]<=V) L=-1,R=-1;
        }
        if(L==-1&&R==-1) ;
        else 
        {
            assert(R>=L),assert(L>=0);
            if(t1.qry(1,L,R,1)==0) ;
            else xd[++k]={L,R};
        }
    }cout<<k<<' ';
    // // for(ll i=1;i<=k;i++) cout<<xd[i].L<<' '<<xd[i].R<<endl;
    sort(xd+1,xd+k+1,cmp);
    t2.build(1,1,ln);

    ll tp=0;
    for(ll i=1;i<=k;i++)
    {
        ll mn=t2.qry(1,xd[i].L,xd[i].R,2);
        t2.upd(1,xd[i].L,xd[i].R,2);
        // cout<<xd[i].L<<' '<<xd[i].R<<' '<<mn<<' ';
        if((mn>=INF)||mn>xd[i].R) xd[++tp]=xd[i];
        // if((mn>=INF)||mn>xd[i].R) {xd[++tp]=xd[i];cout<<"OK\n";}
        // else {cout<<"UHOH\n";}
    }k=tp;ll pt=0,ans=0;// cout<<k<<endl;
    sort(xd+1,xd+k+1,invcmp);
    
    pos[m+1]=INF;// cout<<m<<endl;
    for(ll i=1;i<=k;i++)
    {
        if(pos[pt]>=xd[i].L) continue;
        // cout<<xd[i].L<<' '<<xd[i].R<<' ';
        while(pos[pt+1]<=xd[i].R) pt++;
        // cout<<pt<<endl;
        assert(pt<=m);
        ans++;
    }cout<<m-ans<<endl;
    return ;
}

int main()
{
    ios::sync_with_stdio(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ll T;cin>>T;
    while(T--) Solve();
    return 0;
}