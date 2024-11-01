#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T;
ll n,m,L,V;//use V^2 instead of V itself!
const long double eps=1e-10;
struct o{
    ll d;
    ll v;
    ll a;
};
struct qwe{
    ll l; //P_l or P_r
    ll r;
};
o car[100111];
ll p[100111];
qwe exc[100111];
bool inline operator < (qwe a,qwe b){
    if(a.r==b.r) return a.l<b.l;
    return a.r<b.r;
}
void inline ori(){
    memset(car,0,sizeof(car));
    memset(p,0,sizeof(p));
    memset(exc,0,sizeof(exc));
}
ll inline ltran(ll x){
    int l=0,r=m+1;
    while(l<=r){
        if(l==r) return l;
        if(l+1==r){
            if(p[l]>=x) return l;
            return r;
        }
        int mid=(l+r)/2;
        if(p[mid]==x) return mid;
        else if(p[mid]<x) {
            l=mid+1;
        } else {
            r=mid;
        }
    }
    return -1;
}
ll inline rtran(ll x){
    int l=0,r=m+1;
    while(l<=r){
        if(l==r) return l;
        if(l+1==r){
            if(p[r]<=x) return r;
            return l;
        }
        int mid=(l+r)/2;
        if(p[mid]==x) return mid;
        else if(p[mid]<x) {
            l=mid;
        } else {
            r=mid-1;
        }
    }
    return -1;
}
void inline solve(){
    int cnt=0;
    p[0]=-1e16; p[m+1]=1e16;
    for(int i=1;i<=n;i++){
        ll xl=-1, xr=-1;
        ll tmpl=-1,tmpr=-114;
        if(car[i].a==0){
            if(car[i].v>V){
                xl=car[i].d;
                xr=L;
            } else {
                continue;
            }
        } else if(car[i].a>0){
            xl=car[i].d;
            if(car[i].v<=V){
                xl+=((V-car[i].v)/(2*car[i].a)+1);
            }
            if(xl>L) xl=-1;
            if(xl!=-1) xr=L;
        } else {
            if(car[i].v<=V) continue;
            if((V-car[i].v)%(2*car[i].a)==0){
                xr=min(L,car[i].d+(V-car[i].v)/(2*car[i].a)-1);
            } else {
                xr=min(L,car[i].d+(V-car[i].v)/(2*car[i].a));
            }
            xl=car[i].d;
        }

        if(xl==-1||xr==-1) continue;
        tmpl=ltran(xl);
        tmpr=rtran(xr);
        //cout << ' ' << i << ' ' << xl << ' ' << xr << ' ' << tmpl << ' ' << tmpr << endl;//
        if(tmpl>tmpr||tmpl<1||tmpr>m) continue;
        exc[++cnt]={tmpl,tmpr};
    }
    cout << cnt << ' ';

    sort(exc+1,exc+cnt+1);
    ll maxr=0;
    ll opennum=0;
    for(int i=1;i<=cnt;i++){
        if(maxr<exc[i].l){
            opennum++;
            maxr=exc[i].r;
        }
    }

    cout << m-opennum << endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
    cin >> T;
    ll tmpd,tmpv,tmpa;
    for(int qr=1;qr<=T;qr++){
        //ori();
        scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
        V=V*V;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&tmpd,&tmpv,&tmpa);
            car[i]={tmpd,tmpv*tmpv,tmpa};
        }
        for(int i=1;i<=m;i++){
            scanf("%lld",&p[i]);
        }
        solve();
    }
	return 0;
}
/*
DUO CE YAO QING KONG!
*/
