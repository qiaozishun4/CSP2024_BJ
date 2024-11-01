#include<bits/stdc++.h>
using namespace std;

int n, amax = -1, amin = 1234567;
int a[200000], t[200000] = {};
int ans, cnt = 0;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    ans = n;
    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        amax = max(amax, a[i]);
        amin = min(amin, a[i]);
        t[a[i]]++;
    }
    for(int i = amin;i <= amax;i++) {
        if(!t[i]) continue;
        int x = min(cnt, t[i]);
        ans -= x;
        cnt -= x;
        cnt += t[i];

    }
    printf("%d", ans);
    return 0;
}

