#include<bits/stdc++.h>
using namespace std;

int n;
set<string> st;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string s;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>s;
        st.insert(s);
    }
    cout<<52-st.size();
    return 0;
}

