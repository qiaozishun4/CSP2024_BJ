#include <iostream>
using namespace std;

int T;
int n, ans;
int a[200005];

void dfs(int p, int last_red, int last_blue, int sum) {
    if (p > n) {
        ans = max(ans, sum);
        return;
    }
    dfs(p+1, a[p], last_blue, sum+(a[p]==last_red)?a[p]:0);
    dfs(p+1, last_red, a[p], sum+(a[p]==last_blue)?a[p]:0);
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        dfs(1, -1, -1, 0);
        cout << ans << endl;
    }
    return 0;
}
