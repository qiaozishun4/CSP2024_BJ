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

int T,n,m,L,V,d[100005],v[100005],a[100005],ok[100005],p[100005],nxt[1000005],ans1,ans2;
vector <pair<int,int>> nd;
bool cmp(pair<int,int> xx,pair<int,int> yy) {return xx.fi>yy.fi;}

int calcv(int x,int ds)
{
    return v[x]*v[x]+2ll*a[x]*ds;
}
int isc(int x,int wz)
{
    if(wz==-1||d[x]>wz) return 0;
    return calcv(x,wz-d[x])>V*V;
}
int ck(int x) {if(a[x]<0) return isc(x,nxt[d[x]]); else return isc(x,p[m]);}

int calcs(int x,int tv)
{
    int fz=tv*tv-v[x]*v[x]; int fm=a[x]*2;
    if(fz==0) return d[x];
    if(fz<0) fz*=-1,fm*=-1;
    return d[x]+(fz-1)/fm+1;
}
int calcs2(int x,int tv)
{
    int fz=tv*tv-v[x]*v[x]; int fm=a[x]*2;
    return d[x]+fz/fm;
}
void solve(int x)
{
    if(a[x]>=0&&v[x]>V) return nd.pb(mp(d[x],L)),void();
    else if(a[x]>0) return nd.pb(mp(calcs2(x,V)+1,L)),void();
    else if(a[x]<0) nd.pb(mp(d[x],min(L,calcs(x,V)-1)));
}

signed main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>L>>V; ans1=ans2=0;
        for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
        for(int i=0;i<=L;i++) nxt[i]=-1;
        memset(ok,0,sizeof(ok));
        for(int i=1;i<=m;i++) cin>>p[i],nxt[p[i]]=p[i];
        for(int i=L-1;i>=0;i--) if(nxt[i]==-1) nxt[i]=nxt[i+1];
        for(int i=1;i<=n;i++) ok[i]=ck(i),ans1+=ok[i];
        cout<<ans1<<" ";
        nd.clear();
        for(int i=1;i<=n;i++) if(ok[i]) solve(i);
        sort(nd.begin(),nd.end(),cmp);
        int lst=1000000000;
        for(auto i:nd)
        {
            if(i.se>=lst) continue; ans2++; lst=nxt[i.fi];
        }
        cout<<m-ans2<<endl;
    }
}
