#include<bits/stdc++.h>
#define ll int
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define pll pair<ll,ll>
#define mkp make_pair
using namespace std;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
    {
        if(ch=='-')
        {
            f=-1;
        }
        ch=getchar();
    }
    while(isdigit(ch))
    {
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x*f;
}
struct node
{
    ll d,v,a;
} c[100005];
ll p[100005];
struct seg{
    ll l,r;
}xd[100005];
bool cmp(seg a,seg b){
    if(a.l==b.l){
        return a.r<b.r;
    }
    return a.l<b.l;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ll _=read();
    while(_--)
    {
        ll n=read(),m=read(),L=read(),V=read();
        rep(i,1,n)
        {
            c[i]=node{read(),read(),read()};
        }
        rep(i,1,m)
        {
            p[i]=read();
        }
        ll cnt=0;
        ll tot=0;
        rep(i,1,n)
        {
            if(c[i].a==0)
            {
                if(c[i].v>V)
                {
                    ll wei=lower_bound(p+1,p+m+1,c[i].d)-p;
                    if(wei!=m+1)
                    {
                        xd[++tot].l=wei,xd[tot].r=m;
                        cnt++;
                    }
                }
                continue;
            }
            if(c[i].a>0)
            {
                if(c[i].v>V)
                {
                    ll wei=lower_bound(p+1,p+m+1,c[i].d)-p;
                    if(wei!=m+1)
                    {
                        xd[++tot].l=wei,xd[tot].r=m;
                        cnt++;
                    }
                }
                else if(c[i].v==V)
                {
                    ll wei=upper_bound(p+1,p+m+1,c[i].d)-p;
                    if(wei!=m+1)
                    {
                        xd[++tot].l=wei,xd[tot].r=m;
                        cnt++;
                    }
                }
                else
                {
                    ll t=V*V-c[i].v*c[i].v,cf=2*c[i].a;
                    ll wei=upper_bound(p+1,p+m+1,c[i].d+t/cf)-p;
                    if(wei!=m+1)
                    {
                        xd[++tot].l=wei,xd[tot].r=m;
                        cnt++;
                    }
                }
            }
            else
            {
                if(c[i].v<=V)
                {
                    continue;
                }
                ll t=V*V-c[i].v*c[i].v,cf=2*c[i].a;
                t*=-1,cf*=-1;
                ll twei=lower_bound(p+1,p+m+1,c[i].d)-p,wei=lower_bound(p+1,p+m+1,c[i].d+(t+cf-1)/cf)-p-1;
                if(wei>=twei)
                {
                    xd[++tot].l=twei,xd[tot].r=wei;
                    cnt++;
                }
            }
        }
        printf("%d ",cnt);
        sort(xd+1,xd+tot+1,cmp);
        ll ans=0;
        ll nl=-1,nr=-1;
        rep(i,1,tot){
            if(nl==-1){
                nl=xd[i].l,nr=xd[i].r;
            }
            if(xd[i].l>nr){
                ans++;
                nl=xd[i].l,nr=xd[i].r;
                continue;
            }
            nl=max(nl,xd[i].l);
            nr=min(nr,xd[i].r);
        }
        if(nl!=-1){
            ans++;
        }
        printf("%d\n",m-ans);
    }
    return 0;
}
