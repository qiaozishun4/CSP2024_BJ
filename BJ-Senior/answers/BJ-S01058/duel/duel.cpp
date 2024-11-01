#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, t[N], maxr = -1;
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int r;
        maxr = max(maxr, r);
        scanf("%d", &r);
        t[r]++;
    }
    int cnt = 0, ans = n;
    for (int i = maxr; i >= 1; i--) {
        if (t[i] >= cnt) ans -= cnt, cnt = t[i];
        else ans -= t[i];
    }
    printf("%d", ans);
    return 0;
}