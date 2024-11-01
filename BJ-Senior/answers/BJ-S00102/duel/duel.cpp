#include <bits/stdc++.h>
using namespace std;
int n, a[100005], cnt = 0;
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int first, last;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            first = 1;
            last = 1;
            continue;
        }
        if (a[i] > a[first]) first++;
        last++;
    }
    cout << n - first + 1 <<endl;
    return 0;
}
