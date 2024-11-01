#include<bits/stdc++.h>
using namespace std;
int n;
set<string> st;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string y;
        cin>>y;
        st.insert(y);
    }
    cout<<52-st.size();
    return 0;
}
