#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int n, a[MAXN];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int p = 1, q = 1;
    int ans = 0;
    while (q <= n)
    {
        if (a[q] > a[p])
        {
            ans++;
            p++;
            q++;
        }
        else
        {
            while (q < n && a[q] == a[q + 1])
                q++;
            q++;
        }
    }
    cout << n - ans << '\n';
    return 0;
}
