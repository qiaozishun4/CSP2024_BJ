#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    set<string> st;
    int n,cnt=0;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin >> s;
        st.insert(s);
    }
    for(auto i:st)
    {
        cnt++;
    }
    cout << 52-cnt;
    return 0;
}