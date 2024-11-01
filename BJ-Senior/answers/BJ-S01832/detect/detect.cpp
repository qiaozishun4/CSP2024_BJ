#include <bits/stdc++.h>
using namespace std;
int d[100005], v[100005], a[100005], p[100005];
int t, n, m, l, V;

int f () {
     int ans = 0;
     for (int i = 1;i <= n;i++)
     {
         if (v[i] > V)
         {
             ans++;
         }
     }
     return ans;
}

int f1 () {
    int mn = l + 5, ans = 0;
    if (f() == 0)
    {
        return m;
    }
    else
    {
        for (int i = 1;i <= n;i++)
        {
            if (v[i] > V)
            {
                mn = min(mn, d[i]);
            }
        }
        for (int i = 1;i <= m;i++)
        {
            if (mn < p[i])
            {
                ans++;
            }
        }
        return ans;
    }
}

int main () {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> l >> V;
        for (int i = 1;i <= n;i++)
        {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i = 1;i <= m;i++)
        {
            cin >> p[i];
        }
        cout << f() << " " << f1() << endl;
    }
    return 0;
}