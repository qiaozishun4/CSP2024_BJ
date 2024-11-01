#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N];
signed main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, sum = -1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    for (int i = 1; i <= N; i++) {
        if (a[i]) sum = max(sum, a[i]);
    }
    cout << sum;
    return 0;
}
