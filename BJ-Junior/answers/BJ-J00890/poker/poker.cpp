#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i++)
#define pll pair<ll,ll>
#define mkp make_pair
using namespace std;
set<string> st;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    ll n;
    cin>>n;
    rep(i,1,n){
        string s;
        cin>>s;
        st.insert(s);
    }
    cout<<52-st.size();
    return 0;
}
