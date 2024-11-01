#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, ans = 0;
map<int, int> mp;
int a[200010], vis[200010];
void dfs(int step)
{
    if(step > n)
    {
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            int pos = 0;
            for(int j = i - 1; j >= 1; j--)
            {
                if(vis[i] == vis[j])
                {
                    pos = j;
                    break;
                }
            }
            if(pos && a[i] == a[pos])
                sum += a[i];
        }
        ans = max(ans, sum);
        return;
    }
    vis[step] = 0;
    dfs(step + 1);
    vis[step] = 1;
    dfs(step + 1);
}
signed main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        if(n <= 15)
        {
            ans = 0;
            dfs(1);
            cout << ans << endl;
            continue;
        }
        ans = 0;
        mp.clear();
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(mp.count(a[i]) && mp[a[i]])
            {
                ans += a[i];
                mp[a[i]]--;
            }
            else
                mp[a[i]]++;
        }
        cout << ans << endl;
    }
    return 0;
}
