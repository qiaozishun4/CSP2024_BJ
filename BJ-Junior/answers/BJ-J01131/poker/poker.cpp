#include<bits/stdc++.h>
using namespace std;
set<string>st;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        st.insert(s);
    }
    cout<<52-st.size();
    return 0;
}
