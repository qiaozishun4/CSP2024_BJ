#include<bits/stdc++.h>
using namespace std;
const int maxn = 200100;
const int maxa = 1001000;
int T, n;
long long F1[maxn], F2[maxn], F3[maxn], maxF[maxn];
long long a[maxn], d[maxn];
int lst[maxa];
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        memset(lst, 0, sizeof(lst));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", a + i);
            d[i] = a[i] * (a[i] == a[i - 1]);
            d[i] += d[i - 1];
        }
        F1[1] = 0;
        F2[1] = 0;
        F3[1] = 0;
        F1[2] = 0;
        F2[2] = a[2] * (a[2] == a[1]);
        F3[2] = F2[2];
        lst[a[1]] = 1;
        lst[a[2]] = 2;

        maxF[1] = F1[1] - d[1];
        maxF[2] = max(maxF[1], F1[2] - d[2]);

        for (int i = 3; i <= n; i++) {
            F1[i] = 0;
            F2[i] = 0;
            F3[i] = 0;

            F1[i] = maxF[i - 1] + d[i - 1];

            if (lst[a[i]] != 0) {
                int j = lst[a[i]];
                F1[i] = max(F1[j + 1] + d[i - 1] - d[j + 1] + a[i], F1[i]);
            }

            maxF[i] = max(maxF[i - 1], F1[i] - d[i]);

            F2[i] = F3[i - 1] + a[i] * (a[i] == a[i - 1]);
            F3[i] = max(F1[i], F2[i]);
            lst[a[i]] = i;
        }

        cout << F3[n] << endl;
    }
    return 0;
}
