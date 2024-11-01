#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int a[maxn], tmp[maxn];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);

    int n, mxa = 0, ans = 0; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], tmp[a[i]]++, mxa = max(mxa, a[i]);
    for (int i = 1; i <= mxa; i++) ans = max(ans, tmp[i]);
    cout << ans;
    return 0;
}