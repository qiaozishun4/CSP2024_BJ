#include <bits/stdc++.h>
using namespace std;

int a[200005], c[200005], n;
bool col[200005];
long long m;

void reset() {
    memset(c, 0, sizeof(c));
    memset(col, 0, sizeof(col));
    m = 0;
}

void dfs(int k = 0) {
    if (k > n) {
        long long res = 0;
        for (int i = 1; i <= n; i ++) {
            res += c[i];
        }
        m = max(m, res);
        return ;
    }
    for (int i = k - 1; i >= 1; i --) {
        if (col[i] == col[k]) {
            if (a[i] == a[k]) {
                c[k] = a[k];
            }
            break;
        }
    }
    col[k + 1] = 0;
    dfs(k + 1);
    col[k + 1] = 1;
    dfs(k + 1);
    c[k] = 0;
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while (T --) {
        reset();
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            cin >> a[i];
        }
        dfs();
        cout << m << '\n';
    }
    return 0;
}

