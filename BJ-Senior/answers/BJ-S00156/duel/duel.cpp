#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int n, a[N];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    // for (int i = 1; i <= n; i++)
    //     if (a[i] != a[i - 1])
    //         printf("a[%d] = %d\n", i, a[i]);
    int i, j;
    for (i = 1, j = 2; j <= n; i++, j++) {
        while (j <= n && a[i] == a[j]) j++;
        if (j > n) break;
    }
    cout << n - i + 1 << endl;
    return 0;
}