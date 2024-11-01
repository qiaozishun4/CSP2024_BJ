#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
int a[N];
bool f[N];
void solve()
{
    int n;
    ll sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < (1 << n); i++)
    {
        ll ans = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j)) f[j] = true;
            else f[j] = false;
        for (int j = 0; j < n; j++)
        {
            int pos = n + 1;
            for (int k = j - 1; k >= 0; k--)
                if (f[j] == f[k]) { pos = k; break; }
            if (a[j] == a[pos]) ans += a[j];
        }
        sum = max(sum, ans);
    }
    cout << sum << endl;
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}