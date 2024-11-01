#include <bits/stdc++.h>
using namespace std;
set<string> st;
int n;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    while(n--) {
        string s; cin >> s;
        st.insert(s);
    }
    cout << 52 - st.size() << endl;
    return 0;
}
