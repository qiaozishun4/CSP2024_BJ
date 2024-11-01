#include<bits/stdc++.h>

using namespace std;

int n;
string s;
set<string> st;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        st.insert(s);
    }
    cout<<52-st.size()<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
