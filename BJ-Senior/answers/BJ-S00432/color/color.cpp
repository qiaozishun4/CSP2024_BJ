#include <iostream>
using namespace std;

int n;
int ans = -1;
int a[200005];

void dfs(int pos, int red, int blu, int sum)
{
    if (pos == n)
    {
        if (a[n] == red || a[n] == blu)
        {
            ans = max(ans, sum + a[n]);
        }
        else
        {
            ans = max(ans, sum);
        }
        return;
    }
    if (a[pos] == red)
    {
        dfs(pos + 1, a[pos], blu, sum + a[pos]);
    }
    else
    {
        dfs(pos + 1, a[pos], blu, sum);
    }
    if (a[pos] == blu)
    {
        dfs(pos + 1, red, a[pos], sum + a[pos]);
    }
    else
    {
        dfs(pos + 1, red, a[pos], sum);
    }
}

int main()
{
    //freopen("color.in", "r", stdin);
    //freopen("color.out", "W", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        ans = -1;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        dfs(1, 0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
