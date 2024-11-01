#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[200002];
bool vis[200002];
ll pre[200002];
bool color[200002];
ll ans;
void dfs(ll cur)
{
    if(cur == n + 1)
    {
        ll tans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i - 1; j >= 1; j--)
            {
                if(color[i] == color[j])
                {
                    if(a[i] == a[j])
                        tans += a[i];
                    // cout << i << ":" << j << "\n";
                    break;
                }
            }
            // cout << color[i] << " ";
        }
        ans = max(ans, tans);
        return ;
    }
    color[cur] = 0;
    dfs(cur + 1);
    color[cur] = 1;
    dfs(cur + 1);
    return ;
}
void work()
{
    ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for(int j = i - 1; j >= 1; j--)
        {
            if(a[i] == a[j])
            {
                vis[i] = 1;
                pre[i] = j;
                break;
            }
        }
        if(pre[i] == 0)
        {
            pre[i] = 2147483647;
        }
    }
    if(n <= 20)
    {
        dfs(1);
        cout << ans << "\n";
        return ;
    }
    for(int i = n; i >= 1; i--)
    // for(int i = 1; i <= n; i++)
    {
        ll redid, blueid;
        redid = blueid = -1;
        for(int j = i + 1; j <= n; j++)
        {
            if(color[j] == 0 && redid == -1)
            {
                redid = j;
            }
            if(color[j] == 1 && blueid == -1)
            {
                blueid = j;
            }
        }
        if(redid == -1)
        {
            color[i] = 0;
        }
        else if(pre[redid] == i)
        {
            color[i] = 0;
        }
        else if(blueid == -1)
        {
            color[i] = 1;
        }
        // else if(pre[redid] == i && pre[blueid] == i)
        // {
        //     if(a[redid] > a[blueid])
        //     {
        //         color[i] = 0;
        //     }
        //     else
        //     {
        //         color[i] = 1;
        //     }
        // }
        else if(pre[blueid] == i)
        {
            color[i] = 1;
        }
        else if(pre[redid] > i)
        {
            color[i] = 0;
        }
        else if(pre[blueid] > i)
        {
            color[i] = 1;
        }
        else if(a[redid] < a[blueid])
        {
            color[i] = 0;
        }
        else
        {
            color[i] = 1;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = i - 1; j >= 1; j--)
        {
            if(color[i] == color[j])
            {
                if(a[i] == a[j])
                    ans += a[i];
                // cout << i << ":" << j << "\n";
                break;
            }
        }
        // cout << color[i] << " ";
    }
    // cout << "\n";
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ll t;
    cin >> t;
    // t = 6;
    while(t--)
        work();
    return 0;
}