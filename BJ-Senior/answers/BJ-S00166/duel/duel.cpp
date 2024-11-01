#include <bits/stdc++.h>
using namespace std;

int a[100005], b[100005], f[100005];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    //HF#24THMC
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == a[i - 1]) b[i] = b[i - 1];
        else b[i] = b[i - 1] + 1;
    }
    for (int i = 1; i <= n; ++i) f[b[i]]++;
    int cnt = n, sum = 0;
    for (int i = n; i >= 1; --i)
    {
        if (f[i] >= sum)
        {
            cnt -= sum;
            sum = 0;
        }
        else
        {
            cnt -= f[i];
            sum -= f[i];
        }
        sum += f[i];
    }
    cout << cnt << endl;
    return 0;
}
