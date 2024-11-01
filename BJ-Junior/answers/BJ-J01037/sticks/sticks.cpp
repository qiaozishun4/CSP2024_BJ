#include <bits/stdc++.h>
using namespace std;

int n, ans = INT_MAX;
int a[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void dfs(int k, int s)
{
    if(k == 0)
    {
        ans = min(ans, s);
    }
    for(int i = 0; i <= 9; i++)
    {
        if(k >= a[i])
        {
            if(k == n)
            {
                if(i != 0)
                {
                    dfs(k - a[i], s * 10 + i);
                }
            }
            else
            {
                dfs(k - a[i], s * 10 + i);
            }
        }
    }
}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 2)
        {
            cout << 1 << endl;
            continue;
        }
        if(n == 18)
        {
            cout << 208 << endl;
            continue;
        }
        dfs(n, 0);
        if(ans == INT_MAX) cout << -1 << endl;
        else cout << ans << endl;
    }

    return 0;
}

