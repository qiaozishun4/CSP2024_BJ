#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    int i = 1, j = 1;
    for(; i <= n; ++i) if(a[i] > a[j]) ++j;
    printf("%d", n - j + 1);
    return 0;
}