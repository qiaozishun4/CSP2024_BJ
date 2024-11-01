#include <bits/stdc++.h>
using namespace std;

int a[100010];
int n, cnt = 0;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int x = 0;
    for (int i = 0; i < n;) {
        cnt = 1;
        int sum = 1;
        for (int j = i + 1; j < n && a[j] == a[i]; j++) {
            cnt++;
            sum++;
            a[j] = 1e9;
        }
        x = max(x, cnt);
        a[i] = 1e9;
        sort(a, a + n);
        n -= sum;
    }
    cout << x;
    return 0;
}