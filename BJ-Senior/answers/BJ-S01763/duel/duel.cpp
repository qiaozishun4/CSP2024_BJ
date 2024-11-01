#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LL __int128

const int N = 1e5 + 5;
int n, a[N];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a+1, a+1+n);

    int l = 1, r = 2, res = n;
    while(r <= n) {
        if(a[l] < a[r]) {
            l++; r++; res--;
        } else r++;
    }

    printf("%d\n", res);
    return 0;
}
