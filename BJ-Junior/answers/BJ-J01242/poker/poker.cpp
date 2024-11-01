#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
set <string> st;
signed main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        st.insert(s);
    }
    cout << 52 - st.size();
    return 0;
}