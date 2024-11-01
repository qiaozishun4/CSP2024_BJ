#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int last[1000010], cur[1000010], a[1000010], op[1000010];
long long f[1000010];

long long math(int l, int r)
{
    if (l >= r) return 0;
    if (a[l + 1] == a[l - 1]) return a[l + 1];
    return 0;
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        memset(last, 0, sizeof(last));
        memset(f, 0, sizeof(f));
        memset(cur, 0, sizeof(cur));
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &op[i]);
        }
        long long ans = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (op[i] == op[i - 1])
            {
                ans += op[i];
                continue;
            }
            else a[++cnt] = op[i];
            last[cnt] = cur[a[cnt]];
            cur[a[cnt]] = cnt;
        }
        n = cnt;
        for (int i = 1; i <= n; i++)
        {
            if (last[i] != 0) f[i] = max(f[last[i] + 1] + a[i], f[i - 1]);
            else f[i] = f[i - 1];
            //cout << i << " " << f[last[i] + 1] << " " << a[i] << " " << " " << f[i] << endl;
        }
        cout << f[n] + ans << endl;
    }
    return 0;
}
