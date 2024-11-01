#include<bits/stdc++.h>
using namespace std;

set<string> st;
string a;

int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a;
        st.insert(a);
    }
    cout<<52-st.size();
    return 0;
}
