#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N], cnt[N], sum;
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int lst = 0;
    for (int i = 2; i <= 100000; i++) {
        lst += cnt[i - 1];
        if (cnt[i] >= lst) {
            sum += lst;
            lst = 0;
        } else {
            sum += cnt[i];
            lst -= cnt[i];
        }
    }
    cout << (n - sum) << '\n';
    return 0;
}
