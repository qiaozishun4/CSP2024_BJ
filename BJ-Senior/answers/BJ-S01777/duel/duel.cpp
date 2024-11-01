// 100pts
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 9;
int n, a[N];
multiset<int> st;
signed main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        st.insert(a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        auto it = st.lower_bound(a[i]);
        if (it != st.begin()) it--;
        if (*it < a[i]) st.erase(it);
    }
    printf("%d\n", (int)(st.size()));
    fclose(stdin), fclose(stdout);
    return 0;
}