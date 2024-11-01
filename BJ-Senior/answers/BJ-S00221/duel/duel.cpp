//Wrote by Timmy in October 26th
//I wish I could have 100 points in this problem
#include <bits/stdc++.h>
using namespace std;
multiset <int> st;
int a[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,ans; cin>>n; ans=n;
    for (int i=1; i<=n; i++){
        cin>>a[i];
        st.insert(a[i]);
    }sort(a+1,a+n+1);
    for (int i=1; i<=n; i++){
        auto it=st.lower_bound(a[i]);
        if (it!=st.begin()) it--,st.erase(it),ans--;
    }cout<<ans; return 0;
}
