#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int a[N], cnt[N], cnt2[N];
set<int> st;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        st.insert(a[i]);
        cnt[a[i]]++;
        cnt2[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (st.size() == 1) {
            break;
        }
        auto it = st.upper_bound(a[i]);
        if (it == st.end()) {
            continue;
        }
        cnt[a[i]]--;
        cnt2[a[i]]--;
        cnt[*it]--;
        if (!cnt[a[i]]) st.erase(a[i]);
        if (!cnt[*it]) st.erase(*it);
    }
    long long ans = 0;
    for (int i = 1; i <= (int)1e5; i++) ans += cnt2[i];
    cout << ans;
    return 0;
}