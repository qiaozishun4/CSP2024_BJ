#include <bits/stdc++.h>
using namespace std;
struct S{
    int u = 0;
    int r = 0;
}t[100005];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, a[100005];
    cin >> n;
    for (int i = 1; i <= n; i++) {
            cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i] && t[i].u == 0 && t[i].r == 0 && t[j].r == 0) {
                t[i].u++;
                t[j].r++;
                break;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (t[i].r == 0) sum++;
    }
    cout << sum;
    return 0;
}
