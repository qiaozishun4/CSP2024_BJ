#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll N=1e6+10,M=2e5+10;
struct D{
    ll x,y;
    bool operator<(const D &o)const{
    return y<o.y;}
}q[M];
ll c[M],pr[N],sf[N],p[N],t,n,m,l,v;
ll u(ll x,ll y){
return x/y+bool(x%y);}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&n,&m,&l,&v);
        ll f=0,k=0;
        for(ll i=1;i<=n;i++){
            ll d,V,a;
            scanf("%lld%lld%lld",&d,&V,&a);
            ll s=v*v-V*V;
            if(V>v){//v>k
                if(a>=0) q[i]={d,l};
                else q[i]={d,min(l,d+u(-s,-2*a)-1)};//no-
            }else{
                if(a>0) q[i]={d+s/(2*a)+1,l};
                else q[i]={1,0};
            }
        }
        memset(pr,0,sizeof(pr)),memset(sf,0,sizeof(sf));//no
        for(ll i=1;i<=m;i++){
        ll a; scanf("%lld",&a),pr[a]=sf[a]=i;}
        sf[l+1]=m+1;//no
        for(ll i=0;i<=l;i++) if(!pr[i]) pr[i]=pr[i-1];//1
        for(ll i=l;i>=0;i--) if(!sf[i]) sf[i]=sf[i+1];
        for(ll i=1;i<=n;i++){
            D tp=q[i];
            if(tp.x<=tp.y){
                ll X=sf[tp.x],Y=pr[tp.y];//pr
                if(X<=Y) q[++f]={X,Y};//<
            }
        }
        sort(q+1,q+f+1),memset(c,0,sizeof(c));//nomem
        for(ll i=1;i<=f;i++){
            ll tp=0;
            for(ll j=q[i].y;j;j-=j&-j) tp+=c[j];
            if(q[i].x){//noif
            for(ll j=q[i].x-1;j;j-=j&-j) tp-=c[j];}
            if(tp) continue; k++;
            for(ll j=q[i].y;j<=m;j+=j&-j) c[j]++;
        }
        printf("%lld %lld\n",f,m-k);//k
    }
    return 0;
}
