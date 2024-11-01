#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
using namespace std;
typedef long long LL;
LL N = 110;
LL n;
set<string> st;
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        st.insert(s);
    }

    printf("%lld\n", 52 - st.size());
    return 0;
}