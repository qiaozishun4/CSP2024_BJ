#include <bits/stdc++.h>
using namespace std;
const int M = 1e5;
int n, r, cnt[M + 5], ans, last;
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    ans = n;
    while (n--) {
        cin >> r;
        cnt[r]++;
    }
    for (int i = 1; i < M; i++) {
        if (!cnt[i])
            continue;
        int j = i + 1;
        for ( ; j <= M; j++)
            if (cnt[j])
                break;
        ans -= min(cnt[i], cnt[j]);
        cnt[j] += max(cnt[i] - cnt[j], 0);
        i = j - 1;
    }
    cout << ans << endl;
    return 0;
}
/*
5
1 2 3 4 5
1
*/
/*
9
1 2 3 4 5 4 3 2 1
2
*/
/*
9
1 1 2 2 3 2 2 1 1
4
*/
