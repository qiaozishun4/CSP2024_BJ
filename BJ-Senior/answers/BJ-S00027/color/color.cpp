#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <bits/stdc++.h>
#include <set>

using namespace std;

const int maxn = 15, maxm = 2 * 1e5 + 5;
int n[maxn], a[maxn][maxm];

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n[i]);
        for (int j = 0; j < n[i]; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < t; i++) {
        printf("%d\n", n[i]);
    }
    return 0;
}
