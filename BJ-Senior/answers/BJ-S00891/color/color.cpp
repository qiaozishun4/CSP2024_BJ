#include<bits/stdc++.h>
#define max(a, b) a > b ? a : b
using namespace std;
const int N = 2e5 + 5;
int T, n, a[N], maxn, c[N];
void dfs(int step, int l1, int l2, long long sum) {
    if (step > n) {
        maxn = max(maxn, sum);
        return ;
    }
    c[step] = 1;
    long long retl = sum;
    if (l1 && a[l1] == a[step]) retl += a[l1];
    dfs(step + 1, step, l2, -retl);
    c[step] = 2;
    retl = sum;
    if (l2 && a[step] == a[l2]) retl += a[l2];
    dfs(step + 1, l1, step, retl);
    return;
}
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
    cin >> T;
    while (T --) {
        cin >> n;
        memset(c, 0, sizeof c);
        for (int i = 1; i <= n; i ++) cin >> a[i];
        maxn = INT_MIN;
        dfs(1, 0, 0, 0);
        cout << maxn << '\n';
    }
    return 0;
}
