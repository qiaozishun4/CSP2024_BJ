#include <bits/stdc++.h>
using namespace std;
#define int long long
set<string> st;
int n;
main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++){
        string s;
        cin >> s;
        st.insert(s);
    }
    cout << 52 - st.size();
    return 0;
}