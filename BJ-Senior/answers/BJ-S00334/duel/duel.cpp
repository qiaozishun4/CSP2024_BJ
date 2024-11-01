#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 1e5 + 5;

int n, a[MAXN];
multiset<int> ss;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        ss.insert(a[i]);
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        auto it = ss.upper_bound(a[i]);
        if (it == ss.end()) break;
        ss.erase(it);
        ++ans;
    }
    printf("%d\n", n - ans);
    return 0;
}