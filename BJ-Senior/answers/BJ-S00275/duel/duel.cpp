#include <bits/stdc++.h>
using namespace std;

int a[100005], cnt[100005];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, ans = -1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
        ans = max(ans, cnt[a[i]]);
    }
    cout << ans;
    return 0;
}
