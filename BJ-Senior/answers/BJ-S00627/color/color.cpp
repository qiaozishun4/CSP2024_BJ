#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>

using namespace std;

int nums[200000];
int n, ans;

void dfs(int d, int x, int ll, int lr)
{
    if (d == n)
    {
        ans = max(x, ans);
        return;
    }
    if (ll == -1 && lr == -1)
    {
        dfs(d + 1, x, d, lr);
        dfs(d + 1, x, ll, d);
    }
    else if (ll == -1)
    {
        dfs(d + 1, x, d, lr);
        if (nums[lr] == nums[d])
        {
            dfs(d + 1, x + nums[d], ll, d);
        }
        else
        {
            dfs(d + 1, x, ll, d);
        }
    }
    else if (lr == -1)
    {
        dfs(d + 1, x, ll, d);
        if (nums[ll] == nums[d])
        {
            dfs(d + 1, x + nums[d], d, lr);
        }
        else
        {
            dfs(d + 1, x, d, lr);
        }
    }
    else
    {
        if (nums[lr] == nums[d])
        {
            dfs(d + 1, x + nums[d], ll, d);
        }
        else
        {
            dfs(d + 1, x, ll, d);
        }
        dfs(d + 1, x, ll, d);
        if (nums[ll] == nums[d])
        {
            dfs(d + 1, x + nums[d], d, lr);
        }
        else
        {
            dfs(d + 1, x, d, lr);
        }
    }
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    for (int p = 0; p < t; p++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        dfs(0, 0, -1, -1);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
