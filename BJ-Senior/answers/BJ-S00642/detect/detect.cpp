#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAXN=1e5+5;
const ll MOD=1e9+7;
struct car{
    ll d,v,a;
}a[MAXN];
ll p[MAXN];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ll t;
    while(t--){
        ll n,m,l,v,sum=0;
        for(ll i=1;i<=n;i++){
            cin>>a[i].d>>a[i].v>>a[i].a;
        }
        for(ll i=1;i<=m;i++){
            cin>>p[i];
        }
        for(ll i=1;i<=n;i++){
            for(ll j=a[i].d;p<=m;j++){
                if(a[i].v>v){
                    sum+=1;
                    break;
                }
            }
        }
        cout<<sum<<" "<<sum<<endl;
    }
    return 0;
}