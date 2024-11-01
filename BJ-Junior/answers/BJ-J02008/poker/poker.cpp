#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
set<string> st;
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        st.insert(s);
    }
    cout<<52-st.size();
    return 0;
}
