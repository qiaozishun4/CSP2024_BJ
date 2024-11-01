#include <bits/stdc++.h>
using namespace std;
int a, box[100010];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int maxn = -1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        box[a]++;
        maxn = max(maxn, a);
    }
    int ans = 1;
    for (int i = 1; i <= maxn; ++i)
    {
        ans = max(ans, box[i]);
    }
    cout << ans;

    return 0;
}
