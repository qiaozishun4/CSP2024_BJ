#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;

const int N = 100005;
ll t, n, m, ans, res, cnt1, cnt2, L;
double V, spot[N];
struct A{
    double d, v, a;
}p1[N], p2[N];
bool cmp(A x, A y)
{
    return x.d < y.d;
}
double num1(int i, int j)
{
    return sqrt(p1[i].v * p1[i].v + 2 * p1[i].a * (spot[j] - p1[i].d));
}
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        ans = 0, cnt1 = 0, cnt2 = 0, res = 0;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++)
        {
            double d, v, a;
            cin >> d >> v >> a;
            if (a < 0)
            {
                cnt1++;
                p1[cnt1] = {d, v, a};
            }
            else
            {
                cnt2++;
                p2[cnt2] = {d, v, a};
            }
        }
        for (int i = 1; i <= m; i++)
            cin >> spot[i];
        for (int i = 1; i <= cnt2; i++)
            if (spot[m] >= p2[i].d && V < sqrt(p2[i].v * p2[i].v + 2 * p2[i].a * (spot[m] - p2[i].d)))
            {
                ans = 1;
                res++;
                //cout << i << endl;
            }
        //cout << ans << ' ' << res << endl;
        sort(p1 + 1, p1 + cnt1 + 1, cmp);
        //for (int i = 1; i <= cnt1; i++)
        //    cout << p1[i].d << ' ' << p1[i].v << ' ' << p1[i].a << endl;
        ll j = 1, last = 0;
        for (int i = 1; i <= cnt1; i++)
        {
            while(spot[j] < p1[i].d && j < m) j++;
            if (num1(i, j) > V)
            {
                res++;
                if (last != j) ans++;
                last = j;
            }
        }
        cout << res << ' ' << m - ans << endl;
    }
    return 0;
}

