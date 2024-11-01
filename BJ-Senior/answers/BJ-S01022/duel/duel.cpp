#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, r[N], a[N], rmax, cnt, cntl;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
        a[r[i]]++;
        rmax = max(rmax, r[i]);
    }
    for (int i = 1; i <= rmax; i++)
    {
        if (a[i])
        {
            cnt += min(cntl, a[i]);
            //cout << cnt << " ";//
            cntl = cntl - min(cntl, a[i]) + a[i];
            //cout << cntl << endl;//
        }
    }
    cout << (n - cnt) << endl;

    return 0;
}