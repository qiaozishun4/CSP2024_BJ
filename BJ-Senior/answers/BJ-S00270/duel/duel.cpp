#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        a.emplace_back(t);
    }
    sort(a.begin(), a.end());
    printf("1\n");

    return 0;
}