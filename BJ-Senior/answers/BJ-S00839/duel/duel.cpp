#include <bits/stdc++.h>
using namespace std;
int n, maxn, ans, a[100010], basket[100010];
vector <int> v;
int main () {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &a[i]);
        basket[a[i]] ++ ;
        maxn = max(maxn, a[i]);
    }
    for (int i = 1; i <= maxn; ++ i) if (basket[i] != 0) v.push_back(basket[i]);
    ans = n;
    for (int i = 1; i < v.size(); ++ i) {
        for (int j = 0; j < i; ++ j) {
            if (v[i] >= v[j]) {
                ans -= v[j];
                v[j] = 0;
            }
            else {
                v[j] -= v[i];
                ans -= v[i];
            }
        }
    }
    printf("%d", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
