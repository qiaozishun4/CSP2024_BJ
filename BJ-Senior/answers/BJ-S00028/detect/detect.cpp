#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

const int N = 1000005;
int d[N], v[N], a[N], p[N], cnt[N], cnt1[N], ans[N];

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, l, k;
        cin >> n >> m >> l >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> p[i];
            for (int j = 1; j <= n; j++)
            {
                int A = p[i] - d[j];
                double B = sqrt(1.0 * v[j] * v[j] + 2.0 * a[j] * A);
                if (B > k) cnt[j]++, ans[j] = i, cnt1[i]++;
            }
        }
        priority_queue<int>  q;
        for (int i = 1; i <= m; i++)
            cout << a[i] << endl;
    }
    return 0;
}
