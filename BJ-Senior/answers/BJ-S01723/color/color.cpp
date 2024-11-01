#include<bits/stdc++.h>
using namespace std;
int n, ans;
int a[2005], f[2005][2];//0:blue 1:red

void dfs(int now, int lstb, int lstr, int score)
{
    if(now == n)
    {
        ans = max(ans, score);
        return;
    }
    dfs(now + 1, lstb, a[now + 1], score + (lstr == a[now + 1] ? a[now + 1] : 0));
    dfs(now + 1, a[now + 1], lstr, score + (lstb == a[now + 1] ? a[now + 1] : 0));
    return;
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        memset(f, 0, sizeof(f));
        cin >> n;
        a[0] = ans = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        // for(int i = 1; i <= n; i++)
        // {
        //     for(int j = i + 1; j <= n; j++)
        //     {
        //         mono[i][j] = mono[i][j - 1] + (a[j] == a[j - 1] ? a[j] : 0);
        //     }
        // }
        dfs(1, 0, a[1], 0);
        cout << ans << endl;
    }
    return 0;
}
