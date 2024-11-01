#include <bits/stdc++.h>
using namespace std;
int n, a[100005], tot[100005], c, flag, now1, now2, ans, tp;
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "r", stdout);
    scanf("%d", &n), ans = n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), tot[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= 100000; i++) {
        if(!tot[i]) continue;
        if(!flag) {
            now1 = tp = 1, now2 = tot[i] + 1;
            flag = 1;
        }
        tp += tot[i];
        while(a[now2] == a[now1] && now2 <= n) now2++;
        if(now2 <= n && a[now2] > a[now1]) ans--;
        while(now2 < n && a[now1 + 1] == a[now1] && now1 + 1 <= tp) now2++, now1++, ans--;
        now1 = tp, now2++;
    }
    cout << ans;
    return 0;
}
