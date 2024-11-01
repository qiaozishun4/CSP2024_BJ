#include <bits/stdc++.h>
using namespace std;
int n, A[1000005], maxn = -1e9;
int co(string s) {
    int a[105] = {-1}, b[105] = {-1};
    int sum = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (i) {
            if (s[i - 1] == '0') a[i] = i - 1, b[i] = b[i - 1];
            else a[i] = a[i - 1], b[i] = i - 1;
        }
        // cout << a[i] <<  " " << b[i] << "\n";
        if (s[i] == '0') {
            if (a[i] != -1 && A[a[i] + 1] == A[i + 1]) sum += A[i + 1];
        } else {
            if (b[i] != -1 && A[b[i] + 1] == A[i + 1]) sum += A[i + 1];
        }
    }
    // if (sum != 0) cout << s << "\n";
    return sum;
}
void dfs(int nw, string s) {
    if (nw == n + 1) {
        maxn = max(maxn, co(s));
    }
    if (nw > n) return;
    dfs(nw + 1, s + '0');
    dfs(nw + 1, s + "1");
}
int main() {
        freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while (T --) {
        cin >> n;
        maxn = -1e9;
        for (int i = 1; i <= n; i ++) cin >> A[i];
        dfs(1, "0");
        dfs(1, "1");
        cout << maxn << "\n";
    }

    return 0;
}