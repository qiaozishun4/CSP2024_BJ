#include<bits/stdc++.h>
using namespace std;
const int N=60;
int n;string s[N];set<string> st;
int main()
{
    freopen("poker.in","r",stdin);freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i],st.insert(s[i]);
    cout<<max(0,int(52-st.size()));
    return 0;
}