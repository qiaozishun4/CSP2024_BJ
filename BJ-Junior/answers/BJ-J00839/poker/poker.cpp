#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;string s;
set<string> st;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>s;
        if(!st.count(s)) ans++;
        st.insert(s);
    }
    cout<<52-ans;
    return 0;
}
