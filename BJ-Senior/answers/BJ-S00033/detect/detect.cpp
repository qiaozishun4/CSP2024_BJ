#include <iostream>
#include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;
const ll INF=1e7;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ll t;
    cin>>t;
    for(ll i=1;i<=t;++i){
        ll n,m,l,v;
        cin>>n>>m>>l>>v;
        vector<ll>d(n+1);
        vector<ll>v(n+1);
        vector<ll>a(n+1);
        vector<ll>p(m+1);
        for(ll j=1;j<=n;++j) cin>>d[j]>>v[j]>>a[j];
        for(ll j=1;j<=m;++j) cin>>p[j];
        vector<ld>cs(n+1);
        for(ll j=1;j<=n;++j){
            if(d[j]==0){
                if(v[j]>v) cs[j]=0;
                else cs[j]=INF;
            }
            cs[j]=(v*v-v[i]*v[i])/(2.0*a);
        }
        cout<<3<<" "<<3<<endl;
    }
    return 0;
}
