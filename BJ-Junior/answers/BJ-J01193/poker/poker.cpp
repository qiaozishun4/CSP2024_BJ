#include <bits/stdc++.h>
using namespace std;

set<string>st;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;//6e1
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        //cout<<s<<endl;
        st.insert(s);
    }
    cout<<52-st.size();

    return 0;
}
