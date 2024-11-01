/*
    author: honglan0301
    Goodbye OI~~~~~
    2022.7~2024.7

    BJ jiayou!!!
    RDFZ jiayou!!!
    sexy_goodier,didi123,mc123456,xsap,HYX1124,wuyouka,flying,bunH2O,whdywjd,Max_s_xaM,wzc_IOI_czw,fast_photon,mysterious_cat... jiayou!!!

    accelerate.

    //freopen
    duel1.in duel1.out
    detect1.in detect1.out
    color1.in color1.out
    arena1.in arena1.out
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
mt19937 rnd(time(0));
mt19937_64 rndl(time(0));

int T,n,a[200005],lst[200005],nr[1000005];

struct tree
{
    int mx,tagadd;
}tree[800015];

#define ls(x) (x<<1)
#define rs(x) ((x<<1)|1)
#define m(x) tree[x].mx
#define tg(x) tree[x].tagadd
#define push_up(x) m(x)=max(m(ls(x)),m(rs(x)))
#define cz(k,p) m(p)+=k,tg(p)+=k
#define push_down(x) if(tg(x))cz(tg(x),ls(x)),cz(tg(x),rs(x)),tg(p)=0
#define md(x,y) ((x+y)>>1)

void build(int l,int r,int p)
{
    tg(p)=0; if(l==r) return m(p)=0,void(); int mid=md(l,r);
    build(l,mid,ls(p)); build(mid+1,r,rs(p)); push_up(p);
}
void cza(int l,int r,int x,int y,int k,int p)
{
    if(l>=x&&r<=y) return cz(k,p),void(); int mid=md(l,r); push_down(p);
    if(mid>=x) cza(l,mid,x,y,k,ls(p)); if(mid<y) cza(mid+1,r,x,y,k,rs(p)); push_up(p);
}
int ask(int l,int r,int x,int y,int p)
{
    if(l>=x&&r<=y) return m(p); int mid=md(l,r); push_down(p);
    if(mid>=x&&mid<y) return max(ask(l,mid,x,y,ls(p)),ask(mid+1,r,x,y,rs(p)));
    else if(mid>=x) return ask(l,mid,x,y,ls(p)); else return ask(mid+1,r,x,y,rs(p));
}

signed main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        memset(nr,0,sizeof(nr));
        for(int i=1;i<=n;i++) cin>>a[i],lst[i]=nr[a[i]],nr[a[i]]=i;
        build(0,n,1);
        for(int i=2;i<=n;i++)
        {
            if(a[i-1]==a[i]) cza(0,n,0,i-2,a[i],1);
            int nmx=ask(0,n,0,i-2,1); if(lst[i]&&lst[i]<i-1) nmx=max(nmx,ask(0,n,lst[i],lst[i],1)+a[i]); cza(0,n,i-1,i-1,nmx,1);
        }
        cout<<m(1)<<endl;
    }
}
