#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200002;

ll ans;
int t,n;
ll a[MAXN];
int color[MAXN];

void Clear()
{
    memset(color,0,sizeof(color));
    ans = 0;
}

void Dfs(int step)
{
    if(step == n + 1)
    {
        ll cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            int id = -1;
            for(int j = i - 1;j >= 1;j--)
            {
                if(color[i] == color[j])
                {
                    id = j;
                    break;
                }
            }

            if(id == -1)
                continue;
            if(a[i] == a[id])
                cnt += a[i];
        }

        ans = max(ans,cnt);
        return;
    }

    color[step] = 1;
    Dfs(step + 1);
    color[step] = 2;
    Dfs(step + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    cin >> t;
    while(t--)
    {
        Clear();
        cin >> n;
        for(int i = 1;i <= n;i++)
            cin >> a[i];
        Dfs(1);
        cout << ans << '\n';
    }

    return 0;
}