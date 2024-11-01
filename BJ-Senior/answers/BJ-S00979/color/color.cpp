#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int ans = 0, n, a[N], box[N], l[N];
int f() {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int idx = l[i];
        if (idx == -1 || a[i] != a[idx]) {
            continue;
        } else {
            sum += a[i];
        }
    }
    return sum;
}
void dfs(int cur) {
    if (cur > n) {
        ans = max(ans, f());
        return ;
    }
    for (int i = 0; i <= 1; i++) {
        box[cur] = i;
        for (int j = cur - 1; j >= 1; j--) 
            if (box[cur] == box[j]) {
                l[cur] = j;
                break;
            }
        dfs(cur + 1);
    }
}
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        memset(l, 0, sizeof(l));
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        dfs(1);
        cout << ans << '\n';
    }
    return 0;
}