#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

int n, r[100001];
int c[100001];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    int mx = 0;
    for(int i = 1;i <= n;i++) {
        scanf("%d", &r[i]);
        c[r[i]]++;
        mx = max(mx, r[i]);
    }
    int s = 0;
    for(int i = 1;i <= mx;i++) s = max(s, c[i]);
    printf("%d", s);
    return 0;
}
