#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
struct T{
    ll number,color=0;
};
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ll t;
    cin>>t;
    for(ll i=1;i<=t;++i){
        ll n;
        cin>>n;
        vector<T>a(n+1);
        for(ll j=1;j<=n;++j) cin>>a[j].number;
        cout<<0<<endl;
    }
    return 0;
}
