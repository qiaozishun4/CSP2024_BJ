#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100005], cnt = 1, l_cnt, ans;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; ++i)
        if (a[i] == a[i-1]) ++cnt;
        else
        {
            ans += max(0, l_cnt - cnt);
            if (cnt > l_cnt) ans = max(ans - cnt + l_cnt, 0);
            l_cnt = cnt;
            cnt = 1;
        }
    ans += max(0, l_cnt - cnt);
    cout << ans + cnt;
    return 0;
}
