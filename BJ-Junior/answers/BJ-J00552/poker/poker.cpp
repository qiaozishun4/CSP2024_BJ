#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mp[205][25];
set<string> st;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        st.insert(s);
    }
    cout<<52-st.size();
    return 0;
}
