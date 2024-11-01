#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;

int n, a[N], col[N];
int ans = -2e9;

void dfs(int x)
{
    if (x > n)
    {
        int cnt = 0;
        for (int i = 2; i <= n; i++)
        {
            for (int j = i-1; j >= 1; j--)
            {
                if (col[i] == col[j])
                {
                    if (a[i] == a[j]) cnt += a[i];
                    break;
                }
            }
        }
        ans = max(ans, cnt);
        return;
    }
    dfs(x+1);
    col[x] = 1;
    dfs(x+1);
    col[x] = 0;
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        ans = -2e9;
        dfs(1);
        cout << ans << "\n";
    }
    return 0;
}