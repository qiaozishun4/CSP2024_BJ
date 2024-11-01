#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
string s;
set<string> st;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for (ll i=1;i<=n;i++)
    {
        cin>>s;
        st.insert(s);
    }
    cout<<52-st.size();
    return 0;
}
