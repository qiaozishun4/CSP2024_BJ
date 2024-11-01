#include <iostream>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ll t;
    cin>>t;
    ll n;
    vector<ll>number={0,1,2,4,6,7,8};
    unordered_map<ll,ll>mp;
    mp[0]=6,mp[1]=2,mp[2]=5,mp[4]=4,mp[6]=6;
    mp[7]=3,mp[8]=7;
    for(ll i=1;i<=t;++i){
        cin>>n;
        if(n<2) {cout<<-1<<endl;continue;}
        ll minwei=(n+6)/7;
        ll p=1;
        for(ll j=1;j<=minwei;++j){
            for(ll k=0;k<7;++k){
                if(j==1&&k==0) continue;
                if((n-mp[number[k]]+6)/7>(minwei-j)) continue;
                if((n-mp[number[k]]<0)) continue;
                cout<<number[k];
                n-=mp[number[k]];
                break;
            }
        }
        cout<<endl;
    }
    return 0;
}
