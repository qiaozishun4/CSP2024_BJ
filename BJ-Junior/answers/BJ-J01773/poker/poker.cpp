#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    set<string> st;
    string tmp;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        st.insert(tmp);
    }
    cout<<52-(int)st.size()<<endl;
    return 0;
}
