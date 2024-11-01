#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAXN=1e5+5;
const ll MOD=1e9+7;
ll sd[20]={6,2,5,5,4,5,6,3,7,6},n;
bool cheek(ll x){
    ll sum=0,a;
    while(x!=0){
        a=x%10;
        x/=10;
        sum+=sd[a];
    }
    //cout<<sum<<" ";
    return sum==n;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout)
    ll t,ans=-1;
    cin>>t;
    while(t--){
        cin>>n;
        ans=-1;
        for(ll i=1;i<=1e3;i++){
            if(cheek(i)){
                ans=max(ans,i);
                break;
            }
        }
        cout<<ans<<endl;
        //cout<<cheek(n)<<endl;
    }
    return 0;
}