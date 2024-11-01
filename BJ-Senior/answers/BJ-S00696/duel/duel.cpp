#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[100010], cnt[100010];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cnt[a[i]]++;
    int x = 0;
    for (int i = 1; i <= 100000; i++) {
        x = max(0, x - cnt[i]);
        x += cnt[i];
    }
    cout << x << '\n';
    return 0;
}