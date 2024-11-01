#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, a[N], p[N];
int ans;

void dfs(int id) {
    if (id == n + 1) {
        int res = 0;
        for (int i = 2; i <= n; i++) {
            int flag = 0;
            for (int j = i - 1; j >= 1; j--) {
                if (p[j] == p[i]) {
                    flag = j;
                    break;
                }
            }
            if (!flag) {
                continue;
            }
            if (a[flag] == a[i]) res += a[i];
        }
        ans = max(ans, res);
        return;
    }
    p[id] = 0;
    dfs(id + 1);
    p[id] = 1;
    dfs(id + 1);
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        ans = 0;
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}