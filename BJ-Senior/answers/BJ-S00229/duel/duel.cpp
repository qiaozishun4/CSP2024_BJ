#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = 1e5 + 100;
ll n, r[N], ans;

bool cmp(ll a, ll b)
{
    return a > b;
}

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    ans = n;
    for (int i = 1; i <= n; i++) cin >> r[i];
    sort(r + 1, r + n + 1, cmp);
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i; j <= n; j++)
        {
            if (r[i] > r[j] && r[j] != -1)
            {
                r[j] = -1;
                ans--;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
