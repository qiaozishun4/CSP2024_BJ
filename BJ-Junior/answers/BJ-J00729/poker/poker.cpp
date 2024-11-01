#include<iostream>
#include<cstdio>
#include<string>
#include<set>
using namespace std;
set<string>st;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string str;
    for (int i=1;i<=n;i++)
    {
        cin>>str;
        st.insert(str);
    }
    cout<<52-st.size()<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
