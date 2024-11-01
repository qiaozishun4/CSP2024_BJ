#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n;
int r[MAXN];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &r[i]);
    }
    sort(r + 1, r + n + 1);
    int ans = n;
    for (int i = 2, j = 1; i <= n; i++) {
        if (j >= i) continue;
        if (r[j] < r[i]) ans--, j++; 
    }
    printf("%d\n", ans);
}

// g++ duel.cpp -o duel -O2 -static -std=c++14 && ./duel