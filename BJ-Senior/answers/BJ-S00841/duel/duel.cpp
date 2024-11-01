#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int num[MAXN];
int n, use, ans;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int temp;
        scanf("%d", &temp);
        num[temp]++;
    }

    for (int i = MAXN - 4; i >= 1; i--) {
        if (num[i] < use) {
            ans += num[i];
            use -= num[i];
        } else {
            ans += use;
            use = 0;
        }
        use += num[i];
    }
    printf("%d", n - ans);
    return 0;
}