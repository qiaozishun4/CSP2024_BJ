#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 2e3 + 10;
const ll INF = 0x3f3f3f3f, mod = 998244353;

int n, a[N];
int f[N][N];

void mian()
{
    cin >> n;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        for (int j = 0; j < i; j ++)
        {
            int d1 = (a[i] == a[i - 1]? a[i]: 0);
            int d2 = (a[i] == a[j]? a[i]: 0);
            f[i][j] = max(f[i][j], f[i - 1][j] + d1);
            f[i - 1][i] = max(f[i - 1][i], f[i - 1][j] + d2);
            f[i][i - 1] = max(f[i][i - 1], f[j][i - 1] + d2);
            f[j][i] = max(f[j][i], f[j][i - 1] + d1);
        }
    } 

    int res = 0;
    for (int i = 1; i < n; i ++)
    {
        res = max(res, f[n][i]);
        res = max(res, f[i][n]);
    }
    cout << res << '\n';
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int cases; cin >> cases;
    while (cases --) mian();

    return 0;
}