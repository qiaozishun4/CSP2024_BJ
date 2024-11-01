#include <bits/stdc++.h>
using namespace std;

int a[200005], str[200005], n;
long long mx = 0;

void dfs(int x)
{
    if (x == n + 1)
    {
        long long sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i - 1; j >= 1; --j)
            {
                if (str[i] == str[j])
                {
                    if (a[i] == a[j]) sum += a[i];
                    break;
                }
            }
        }
        mx = max(mx, sum);
        return;
    }
    str[x] = 1;
    dfs(x + 1);
    str[x] = 2;
    dfs(x + 1);
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    //HF#24THMC
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        mx = 0;
        dfs(1);
        cout << mx << endl;
    }
    return 0;
}
