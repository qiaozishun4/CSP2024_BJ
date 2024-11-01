#include <cstdio>
#include <cstring>

const int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int T, n, ans[50001], t[50001], len;
bool zero;

void dfs(int step, int sticks) {
    if (step - 1 > len)
        return ;
    if (sticks == 0) {
        if (step - 1 < len) {
            memcpy(ans, t, sizeof ans);
            len = step - 1;
        } else if (step - 1 == len) {
            for (int i = 1; i <= len; ++i)
                if (ans[i] > t[i]) {
                    memcpy(ans, t, sizeof ans);
                    break;
                } else if (ans[i] < t[i])
                    break;
        }
        return ;
    }
    for (int i = zero; i < 10; ++i)
        if (cost[i] <= sticks) {
            zero = false;
            t[step] = i;
            dfs(step + 1, sticks - cost[i]);
        }
}

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    for (scanf("%d", &T); T--; ) {
        scanf("%d", &n);
        if (n == 1)
            printf("-1\n");
        else if (n % 7 == 0) {
            for (int i = n / 7; i; --i)
                putchar('8');
            putchar('\n');
        } else if (n % 7 == 1) {
            printf("10");
            for (int i = (n - 8) / 7; i; --i)
                putchar('8');
            putchar('\n');
        } else {
            len = 50001;
            zero = true;
            dfs(1, n);
            for (int i = 1; i <= len; ++i)
                printf("%d", ans[i]);
            putchar('\n');
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
