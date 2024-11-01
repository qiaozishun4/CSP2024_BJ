#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
ll t, n, m, L, V, v1[100005], a[100005], b[100005], c[100005], p[1000005], p1[1000005], sum = 0, num = 0;
bool flag = true;
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> m >> L >> V;
        for (int j = 1; j <= n; j++)
        {
            cin >> a[j] >> b[j] >> c[j];
        }
        for (int j = 1; j <= n; j++)
        {
            v1[j] = b[j];
        }
        for (int j = 1; j <= m; j++)
        {
            cin >> p[j];
        }
        for (int j = 1; j <= n; j++)
        {
            for (int k = a[j]; k <= L; k++)
            {
                flag = true;
                v1[j] += c[k];
                for (int l = 1; l <= m; l++)
                {
                    if (k == p[l] && v1[j] > V)
                    {
                        p1[l]++;
                        num++;
                        flag = false;
                    }
                    if (!flag)
                    {
                        break;
                    }
                }
                if (!flag)
                {
                    break;
                }
            }
        }
        for (int j = 1; j <= m; j++)
        {
            if (p[j] == 0)
            {
                sum++;
            }
        }
        cout << num << " " << sum << endl;
        num = 0;
        sum = 0;
        for (int j = 1; j < 100005; j++)
        {
            v1[j] = 0;
            a[j] = 0;
            b[j] = 0;
            c[j] = 0;
        }
        for (int j = 1; j < 1000005; j++)
        {
            p[j] = 0;
            p1[j] = 0;
        }
    }
    return 0;
}
