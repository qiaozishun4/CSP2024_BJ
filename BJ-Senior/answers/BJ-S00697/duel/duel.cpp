#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5;
int n, a[N + 5];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);

    int ans = 0, cnt = 0;
    for (int i = 1; i <= n + 1; ++i)
    {
        if (a[i] != a[i - 1])
        {
            ans = max(0, ans - cnt) + cnt;
            cnt = 0;
        }
        ++cnt;
    }

    cout << ans << endl;

    return 0;
}