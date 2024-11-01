#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

set<string> st;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string s;
    while (n--)
        cin>>s,st.insert(s);
    cout<<52-st.size()<<endl;

    return 0;
}
//orz to nzhtl1477
//rp<<=114514
