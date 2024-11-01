#include<bits/stdc++.h>
#define rd(x) scanf("%lld",&x)
using namespace std;
typedef long long ll;
const ll N=1e6+5;
ll T,n,m,l,V,d[N],v[N],a[N],L[N],R[N],p[N];
struct Node{ll x,y;}f[N];
bool cmp(Node p1,Node p2){
    if(p1.x!=p2.x) return p1.x<p2.x;
    return p1.y<p2.y;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    rd(T);
    while(T--){
        rd(n);rd(m);rd(l);rd(V);
        for(ll i=1;i<=n;i++){
            rd(d[i]);rd(v[i]);rd(a[i]);L[i]=d[i];R[i]=l;
            if(a[i]==0&&v[i]<=V) L[i]=1,R[i]=0;
            if(a[i]>0){
                L[i]=max(L[i],(V*V-v[i]*v[i])/(2*a[i])+d[i]+1);
            }
            if(a[i]<0){
                R[i]=min(R[i],(-(V*V-v[i]*v[i])-2*a[i]-1)/(-2*a[i])+d[i]-1);
            }
        }
        for(ll i=1;i<=m;i++) rd(p[i]);
        ll ans=0;
        for(ll i=1;i<=n;i++){
            ll t=lower_bound(p+1,p+m+1,L[i])-p,t2=upper_bound(p+1,p+m+1,R[i])-p-1;
            if(t>=1&&t2<=m&&t<=t2) f[++ans]=Node{t,t2};
        }
        sort(f+1,f+ans+1,cmp);
        ll ans2=(ans!=0),tmp3=f[1].y;
        for(ll i=2;i<=ans;i++){
            if(tmp3<f[i].x) ans2++,tmp3=f[i].y;
            else tmp3=min(tmp3,f[i].y);
        }
        printf("%lld %lld\n",ans,m-ans2);
    }
    return 0;
}
