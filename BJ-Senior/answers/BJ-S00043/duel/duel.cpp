#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long n, a[maxn], cnt[maxn], ans = 0;
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ans = n;
    long long is = 0;
    for (long long i = 1; i < maxn; i++) {
        if (cnt[i] > 0 && is > 0) {
            if (cnt[i] > is) {
                cnt[i] -= is;
                ans -= is;
                is = 0;
            }
            else {
                is -= cnt[i];
                ans -= cnt[i];
                cnt[i] = 0;
            }
        }
        if (cnt[i + 1] >= cnt[i]) {
            ans -= cnt[i];
            cnt[i + 1] -= cnt[i];
            cnt[i] = 0;
        }
        else {
            ans -= cnt[i + 1];
            is = cnt[i] - cnt[i + 1];
            cnt[i + 1] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
