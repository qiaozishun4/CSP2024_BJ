#include <iostream>
#include <set>
using namespace std;
const int maxn = 1e5 + 10;
int n, a[maxn];
multiset<int> se;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], se.insert(a[i]);
    for (int i = 1; i <= n; i++) {
        auto it = se.lower_bound(a[i]);
        if (it == se.begin()) continue;
        se.erase(--it);
    } cout << se.size() << '\n';
    return 0;
}