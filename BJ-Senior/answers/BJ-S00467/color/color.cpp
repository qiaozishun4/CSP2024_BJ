#include <bits/stdc++.h>
using namespace std;
int vis[2006],a[2006];
int ans;
int n;
void dfs(int cur)
{
    if(cur == n + 1)
    {
        int cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i - 1;j >= 1;j--)
            {
                if(vis[j] == vis[i])
                {
                    if(a[i] == a[j]) cnt += a[i];
                    break;
                }
            }

        }
        ans = max(ans,cnt);
        return;
    }
    vis[cur] = 1;
    dfs(cur + 1);
    vis[cur] = 2;
    dfs(cur + 1);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {

        cin >> n;
        ans = 0;
        memset(vis,0,sizeof(vis));
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}
