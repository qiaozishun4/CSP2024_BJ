#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 10;
int t, n, a[maxn], c[maxn];
string trans(int x) {
    string res;
    while (x) res.push_back((x & 1) + '0'), x >>= 1;
    while (res.size() < n) res.push_back('0');
    reverse(res.begin(), res.end());
    return res;
}
#undef int
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    #define int long long
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        memset(c, 0, sizeof(c));
        cin >> n; int ans = -1;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 0; i < (1 << n); i++) {
            string s = trans(i); int sum = 0;
            // 1代表红, 0代表蓝
            s = "#" + s;
            for (int j = 1; j <= n; j++) {
                bool flag = false; int k;
                for (k = j - 1; k >= 1; k--) 
                    if (s[j] == s[k]) {
                        if (a[j] == a[k]) c[j] = a[j];
                        flag = true; break;
                    }
                if (flag) continue; 
            }
            for (int j = 1; j <= n; j++) sum += c[j];
            ans = max(ans, sum);
        }
        cout << ans << "\n";
    }
    return 0;
}