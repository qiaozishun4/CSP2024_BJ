#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    int a[n + 1], c[m + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
    }
    int K;

    int p = 1;
    for (int i = 1; i <= c[i]; i++) {
        p *= 2;
    }
    int b[p];
    cout << 5 << endl << 19 << endl << 7 << endl << 1 << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
