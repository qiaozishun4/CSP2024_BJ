#include<iostream>
#include<set>
using namespace std;
set<string>st;
int n;
string s;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        st.insert(s);
    }
    cout<<52-st.size();
    fclose(stdin);
    fclose(stdout);
    return 0;
}