#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,l,s,rr,cc;
set<int> st;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> q;
        for(int i=1;i<=n;i++)
        {
            cin >> l;
            for(int i=1;i<=l;i++) cin >> s,st.insert(s);
        }
        for(int i=1;i<=q;i++)
        {
            cin >> rr >> cc;
            if(st.count(cc)>0) cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}

