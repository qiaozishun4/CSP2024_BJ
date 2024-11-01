#include<bits/stdc++.h>
using namespace std;
int n;
string op;
set<string> st;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>op;
        st.insert(op);
    }
    cout<<52-st.size();
}
