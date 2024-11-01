#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5+5;

int n;
int a[N];


signed main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    int ans;

    scanf("%lld", &n);
    for (int i=1;i<=n;i++) {
        scanf("%lld", &a[i]);
    }
    ans = n;

    sort(a+1, a+1+n);

    int l = 1;

    for (int i=2;i<=n;i++) {
        if (a[i]>a[l]) {
            ans--;
            l++;
        }
    }

    cout << ans << endl;

    return 0;
}
