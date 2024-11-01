#include <bits/stdc++.h>
using namespace std;
set<string>st;
string s;
int n;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--)
    {
        cin>>s;
        st.insert(s);
    }
    cout<<52-st.size();
    return 0;
}
