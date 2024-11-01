#include<bits/stdc++.h>
#define int long long
using namespace std;

int ans, s[] = {6, 2, 5, 0, 4, 0, 6, 3, 7, 0}, t, n;
void dfs(int step, int num, int sum)
{
    if(sum > n) return;
    if(sum == n)
    {
        ans = min(ans, num);
        return;
    }
    if(step != 1) dfs(step + 1, num * 10, sum + s[0]);
    for(int i = 1; i <= 9; i++)
    {
        if(i != 3 && i != 5 && i != 9) dfs(step + 1, num * 10 + i, sum + s[i]);
    }
}
signed main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n % 7 == 0)
        {
            for(int i = 1; i <= n / 7; i++) cout << "8";
            cout << endl;
        }
        else
        {
            ans = 1e9;
            dfs(1, 0, 0);
            if(ans == 1e9) cout << -1 << endl;
            else cout << ans << endl;
        }
    }
    return 0;
}
