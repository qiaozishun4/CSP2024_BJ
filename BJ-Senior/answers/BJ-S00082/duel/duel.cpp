/*
Glory Glory Man United
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
int a[N], cnt[N];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i - 1]) tot++;
        cnt[tot]++;
    }
    int ans = 0;
    for (int i = 1; i <= tot; i++)
    {
        ans += max(0, cnt[i] - ans);
    }
    cout << ans << endl;
    return 0;
}