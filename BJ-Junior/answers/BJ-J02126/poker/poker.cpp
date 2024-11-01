#include <bits/stdc++.h>
using namespace std;
string s;
int T;
set<string> st;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        cin>>s;
        st.insert(s);
    }
    printf("%d",52-(int)st.size());
    return 0;
}
