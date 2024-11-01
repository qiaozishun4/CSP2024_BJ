#include<bits/stdc++.h>
using namespace std;
int n;
set<string> st;
int main(void)
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        st.insert(s);
    }
    cout<<52-st.size();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
