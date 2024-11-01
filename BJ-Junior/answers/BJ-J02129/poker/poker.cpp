#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    set<string>st;
    while(n--){
        string s;
        cin>>s;
        st.insert(s);
    }
    int ans=52-st.size();
    cout<<ans;
}
