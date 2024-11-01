#include<bits/stdc++.h>
using namespace std;
int n;
string a;
set<string> st;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        st.insert(a);
    }
    int ans=52-st.size();
    cout<<max(ans,0);
    return 0;
}
