#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
long long n, a[maxn], b[maxn], c[maxn], ans;
long long change(int x) {
    long long ans = 0;
    int k = 0;
    int a[10000];
    while(x) {
        a[k] = x % 2;
        k++;
        x /= 2;
    }

    for (int i = k - 1; i >= 0; i--) {
        ans = ans * 10 + a[i];
    }
    return ans;
}
void solve() {
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < (1 << n); i++) {
        int x = change(i);
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        for (int i = n - 1; i >= 0; i--) {
            b[i] = x % 10;
            x /= 10;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (b[i] == b[j]) {
                    if (a[i] == a[j]) {
                        c[i] = a[i];
                    }
                }
            }
        }
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += c[i];
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return;
}
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
