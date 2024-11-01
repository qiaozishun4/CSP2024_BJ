#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, r[100010];
int cnt[100010], tmp[100010];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &r[i]);

    memcpy(tmp, r, sizeof tmp);
    sort(tmp, tmp + n);
    int m = unique(tmp, tmp + n) - tmp;
    for (int i = 0; i < n; ++i)
        r[i] = lower_bound(tmp, tmp + m, r[i]) - tmp;
    for (int i = 0; i < n; ++i)
        ++cnt[r[i]];

    printf("%d\n", *max_element(cnt, cnt + m));
    return 0;
}
