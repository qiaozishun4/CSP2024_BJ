#include<bits/stdc++.h>
using namespace std;
const int MAX = 20;
long long n, num, ans;
int arr[MAX] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
void dfs(long long cnt, long long now) {
    if (cnt != num) {
        if (now >= ans && ans != -1) return;
        if (cnt == 0 && now != 0) {
            ans = min(ans, now);
            return;
        }
    }
    for (int i = 0; i <= 9; i++) {
        if (now == 0 && i == 0) continue;
        if (cnt >= arr[i]) dfs(cnt - arr[i], now * 10 + i);
    }
    return;
}
int main () {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        ans = INT_MAX;
        dfs(num, 0);
        if (ans != INT_MAX) cout << ans << endl;
        else cout << "-1" << endl;
    }
    fclose(stdin), fclose(stdout);
    return 0;
}