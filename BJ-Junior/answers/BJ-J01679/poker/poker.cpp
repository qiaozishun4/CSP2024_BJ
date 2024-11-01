#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    set<string> st;
    string s;
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        st.insert(s);
    }
    for(auto i:st)ans++;
    cout<<52-ans;
    return 0;
}
