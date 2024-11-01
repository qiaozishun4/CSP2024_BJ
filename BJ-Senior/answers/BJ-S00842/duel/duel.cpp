#include<bits/stdc++.h>
using namespace std;
const int maxn = 100100;
int a[maxn], n;
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + n + 1);
    int ans = n;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && a[i] == a[j]) {
            j++;
        }
        if (j > n) {
            break;
        }
        ans--;
        j++;
    }
    cout << ans;
    return 0;
}
