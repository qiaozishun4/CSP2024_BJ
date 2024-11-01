// cout << "hello_world" << endl;
#include <bits/stdc++.h>
using namespace std;
bool flag[200001];
int t = 0, n = 0, maxn = 0, cnt = 0, a[20001];
void cal(bool f[]) {
    int sum = 0;
    for (int i = 1; i <= cnt; ++i)
        for (int j = i - 1; j >= 1; --j)
            if (a[i] == a[j] && f[i] == f[j]) {
                sum += a[i];
                break;
            }
    maxn = max(maxn, sum);
}
void dfs(int deph, bool f[]) {
    if (deph == cnt) cal(f);
    if (deph == cnt) return;
    f[deph] = 1;
    dfs(deph + 1, f);
    f[deph] = 0;
    dfs(deph + 1, f);
}
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> t;
    while (--t >= 0) {
        maxn = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        bool f[n + 10];
        for (int i = 1; i <= n; ++i) f[i] = 0;
        for (int i = n; i >= 1; --i)
            for (int j = i - 1; j >= 1; --j)
                if (a[i] == a[j]) f[i] = f[j] = 1;
        cnt = 0;
        for (int i = 1; i <= n; ++i)
            if (f[i]) a[++cnt] = a[i];
        for (int i = cnt + 1; i <= n; ++i) a[i] = 0;
        if (!cnt) cout << 0 << endl;
        if (!cnt) continue;
        dfs(1, flag);
        cout << maxn << endl;
    }
    return 0;
}