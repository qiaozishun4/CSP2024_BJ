#include <bits/stdc++.h>
using namespace std;

int T, n, a[200010];
int ans = -1;
void dfs(int step, int last_blue, int last_red, int score)
{
    if(step > n)
    {
        ans = max(score, ans);
        cout << score << endl;
        return ;
    }
    if(a[step] == last_blue) dfs(step + 1, a[step], last_red, score+a[step]);
    else dfs(step + 1, a[step], last_red, score);
    if(a[step] == last_red) dfs(step + 1, last_blue, a[step], score+a[step]);
    else dfs(step + 1, last_blue, a[step], score);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out", "w", stdout);
    cin >>T;
    while(T--)
    {
        cin >>n;
        for(int i = 1; i <= n; i++) cin >>a[i];
        dfs(1, 0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
