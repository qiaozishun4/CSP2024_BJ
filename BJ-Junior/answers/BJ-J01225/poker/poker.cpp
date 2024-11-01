#include<bits/stdc++.h>
using namespace std;
int n;
string str;
set<string> st;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str;
        st.insert(str);
    }
    cout<<52-st.size()<<endl;
    return 0;
}
