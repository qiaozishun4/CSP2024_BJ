#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
const ll N=100005, M=100005;
ll T, n, m, L, V, d[N], v[N], a[N], p[M], l[N], r[N];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
        for(ll i=1;i<=n;i++) scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
        for(ll i=1;i<=m;i++) scanf("%lld",&p[i]);
        sort(p+1,p+m+1);
        for(ll i=1;i<=n;i++){
            if(d[i]<=V){
                if(a[i]<=0){
                    l[i]=r[i]=-1;
                    continue;
                }
                ll vend=v[i]*v[i]+2*a[i]*(L-d[i]);
                if(vend*vend<=V*V){
                    l[i]=r[i]=-1;
                    continue;
                }
                l[i]=(V*V-v[i]*v[i])/2/a[i]+d[i], r[i]=L;
            }
            if(d[i]>V){
                if(a[i]>=0){
                    l[i]=d[i], r[i]=L;
                    continue;
                }
                ll vend=v[i]*v[i]+2*a[i]*(L-d[i]);
                if(vend*vend>V*V){
                    l[i]=d[i], r[i]=L;
                    continue;
                }
                l[i]=d[i], r[i]=(V*V-v[i]*v[i])/2/a[i]+d[i];
            }
        }
        ll cnt=0;
        for(int i=1;i<=n;i++){
            if(l[i]==-1&&r[i]==-1) continue;
            ll x=lower_bound(p+1,p+m+1,l[i]+1)-p, y=upper_bound(p+1,p+m+1,r[i]-1)-p-1;
            if(x<=y) cnt++;
        }
        printf("%lld %lld\n",cnt,m-2);
    }
    return 0;
}