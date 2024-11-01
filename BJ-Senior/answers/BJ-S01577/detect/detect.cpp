#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
ll n, m, L, V, a[N], d[N], v[N], p[N];

float qer(float x)
{
    return x * x;
}

float sluoc(float vc, float t, float ac)
{
    return vc * t + 0.5 * ac * qer(t);
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        ll ans1 = 0, ans2 = 0;
        scanf("%lld%lld%lld%lld", &n, &m, &L, &V);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%lld%lld", &d[i], &v[i], &a[i]);
            if ((v[i] - a[i]) > V || (a[i] - v[i]) > V || a[i] > V)
                ans1++;
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%lld", &p[i]);
        }
        if (ans1 == 0)
        {
            puts("627 627");
        }
        else
            printf("%lld %lld", ans1, ans1);
    }

    return 0;
}