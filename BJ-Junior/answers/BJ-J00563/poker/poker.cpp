#include<bits/stdc++.h>
using namespace std;
set<string> st;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string str;
    while(n--)
    {
        cin>>str;
        st.insert(str);
    }
    cout<<52-st.size();
    return 0;
}

