#include <cstdio>
#include <algorithm>
using namespace std;

int t, n;
int a[20];

int ans;
int last0 = 1, last1 = 0;
void dfs(int step, int tot) {
    if (step > n) {
        ans = max(ans, tot);
        return;
    }

    int tmp = last0;
    last0 = step;
    dfs(step + 1, tot + (a[tmp] == a[step]) * a[step]);
    last0 = tmp;

    tmp = last1;
    last1 = step;
    dfs(step + 1, tot + (a[tmp] == a[step]) * a[step]);
    last1 = tmp;
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        ans = 0;
        dfs(2, 0);
        printf("%d\n", ans);
    }
    return 0;
}
