#include<bits/stdc++.h>
using namespace std;

int co[105], a[105];
int T;
int n, ans = 0;
void dfs(int f)
{
    if(f > n)
    {
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            int tmp = 0;
            for(int j = i - 1; j >= 1; j--)
            {
                if(co[j] == co[i])
                {
                    tmp = j;
                    break;
                }
            }
            if(a[tmp] == a[i])
            {
                cnt += a[i];
            }
        }
        ans = max(ans, cnt);
        return;
    }
    for(int i = 0; i <= 1; i++)
    {
        co[f] = i;
        dfs(f + 1);
        co[f] = 0;
    }
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        memset(co, 0, sizeof(co));
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}
