#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

int n, maxn;
int a[200010];

void dfs(int step, int sum, int lsr, int lsb)
{
    if (step > n)
    {
        maxn = max(maxn, sum);
        return ;
    }
    dfs(step + 1, sum + ((a[step] == lsr) ? a[step] : 0), a[step], lsb);
    dfs(step + 1, sum + ((a[step] == lsb) ? a[step] : 0), lsr, a[step]);
}

signed main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        cin >>n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        maxn = 0;
        dfs(1, 0, 0, 0);
        cout << maxn << endl;
    }
    return 0;
}
