#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int MAXN=1e5+10;
ll p[MAXN];
ll d[MAXN],v[MAXN],a[MAXN];
db l[MAXN],r[MAXN];
struct Node{
    ll lp,rp;
    bool operator<(const Node &q) const {
        if(lp==q.lp) return rp<q.rp;
        return lp<q.lp;
    }
}pp[MAXN];
ll n,m,L,V,cnt=0,ans=0,len=0;
void init(){
    cnt=len=0;
    ans=0;
    memset(pp,0,sizeof(pp));
    memset(p,0,sizeof(p));
    memset(d,0,sizeof(d));
    memset(a,0,sizeof(a));
    memset(v,0,sizeof(v));
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));

}
ll lj(db x){
    ll lft=1,rgt=m,ansl;
    if(x>(db)(p[m])) return LLONG_MAX;
    while(lft<=rgt){
        ll mid=(lft+rgt)>>1ll;
        if(db(p[mid])>=x){
            ansl=mid;
            rgt=mid-1;
        }else lft=mid+1;
    }
    return ansl;
}
ll rj(db x){
    ll lft=1,rgt=m,ansr;
    if(db(p[1])>x) return LLONG_MIN;
    while(lft<=rgt){
        ll mid=(lft+rgt)>>1ll;
        if(db(p[mid])<=x){
            ansr=mid;
            lft=mid+1;
        }else rgt=mid-1;
    }
    return ansr;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    ll T;
    cin>>T;
    while(T--){
        init();
        cin>>n>>m>>L>>V;
        for(int i=1; i<=n; i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]==0){
                if(v[i]<=V) continue;
                l[++len]=db(d[i]);
                r[len]=db(L);
            }else if(a[i]>0){
                db s=((db)(V*V)-(db)(v[i]*v[i]))/(2.0*db(a[i]));
    //            cout<<":"<<(V*V)<<" "<<(v[i]*v[i])<<" "<<2.0*db(a[i])<<endl;
    //            cout<<":"<<i<<" "<<s<<endl;
                if(d[i]+s>L) continue;
                l[++len]=db(d[i])+s;
                r[len]=db(L);

            }else if(a[i]<0){
    //            cout<<114514<<endl;
                if(v[i]<=V) continue;
                db s=(db)((db)(v[i]*v[i])-(db)(V*V))/(2.0*(db)(-a[i]));
    //            cout<<":"<<i<<" "<<((db)(v[i]*v[i])-(db)(V*V))<<" "<<(2.0*(db)(-a[i]))<<" "<<d[i]<<" "<<d[i]+s<<endl;
                l[++len]=db(d[i]);
                r[len]=db(d[i])+s;
            }
        }
        for(int i=1; i<=m; i++){
            cin>>p[i];
        }
        sort(p+1,p+1+m);
//        for(int i=1; i<=m; i++){
//            cout<<p[i]<<" ";
//        }
//        cout<<endl;
        for(int i=1; i<=len; i++){
//            cout<<l[i]<<" "<<r[i]<<endl;
            ll t1=lj(l[i]),t2=rj(r[i]);
//            cout<<t1<<" "<<t2<<endl;
            if(t1<=t2){
                pp[++cnt].lp=t1;
                pp[cnt].rp=t2;
            }
        }
        cout<<cnt<<" ";
        sort(pp+1,pp+1+cnt);
        ll ma,mi;
        for(int i=1; i<=cnt; i++){
//            cout<<i<<" pp[i].lp:"<<pp[i].lp<<" pp[i].rp:"<<pp[i].rp<<" ans:"<<ans<<" ma:"<<ma<<" mi:"<<mi<<endl;
            if((pp[i].lp>=ma&&pp[i].lp<=mi)||(pp[i].rp>=ma&&pp[i].rp<=mi)){
                mi=min(mi,pp[i].rp);
                ma=max(ma,pp[i].lp);
            }else{
                mi=pp[i].rp;
                ma=pp[i].lp;
                ans++;
            }
        }
        cout<<m-ans<<endl;
    }
    return 0;
}
