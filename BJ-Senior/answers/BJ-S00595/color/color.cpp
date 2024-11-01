#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int n, a[100001];
long long ans = 0;
//bool c[100001];

void dfs(int x, int last0, int last1, long long sum) {
    if (x > n) {
        ans = max(ans, sum);
        return ;
    }
    //0
    if (a[x] == a[last0]) dfs(x + 1, x, last1, sum + a[x]);
    else dfs(x + 1, x, last1, sum);
    //1
    if (a[x] == a[last1]) dfs(x + 1, last0, x, sum + a[x]);
    else dfs(x + 1, last0, x, sum);
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        memset(a, 0, sizeof(a));
        //memset(c, 0, sizeof(c));
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        dfs(1, 0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
