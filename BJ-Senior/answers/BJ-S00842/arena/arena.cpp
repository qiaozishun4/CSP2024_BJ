#include<bits/stdc++.h>
using namespace std;
const int maxn = 100100;
int n, m;
int X[4];
int a[maxn], c[maxn];
struct node {
    int l, r, num, winnum;
} d[20][maxn];
int tot = 0;
int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d", c + i);
        ans ^= i;
    }
    int K = 1;
    while (K < n) {
        K *= 2;
    }
    char ch;
    for (int i = 1; (1 << i) <= K; i++) {
        getchar();
        for (int j = (1 << i); j <= K; j += (1 << i)) {
            scanf("%c", &ch);
            d[i][j - (1 << i) + 1] = (node) {j - (1 << i) + 1, j, ch - '0', 0};
        }
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &X[0], &X[1], &X[2], &X[3]);
        cout << ans << endl;
    }
    return 0;
}
