#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAXN=1e5+5;
const ll MOD=1e9+7;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ll t;
    srand(time(0));
    cin>>t;
    for(ll i=1;i<=t;i++){
        cout<<rand()%100000<<endl;
    }
    return 0;
}