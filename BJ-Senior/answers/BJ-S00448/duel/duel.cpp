#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 10e5+3;
int r[N];

int main() {

    freopen("duel.in", "r", stdin);
    freopen("duel.out","w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &r[i]);
    sort(r, r + n);

    int k = -1, cnt = 0;

    for (int i = 0; i < n; i++) {
        k = upper_bound(r + k + 1, r + n, r[i]) - r;
        if (k >= n) break;
        cnt++;
    }

    printf("%d\n", n - cnt);

    return 0;
}
