#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAXN=1e5+5;
const ll MOD=1e9+7;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ll n;
    set<string> st;
    string x;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>x;
        st.insert(x);
    }
    cout<<52-st.size()<<endl;
    return 0;
}