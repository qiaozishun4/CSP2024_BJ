#include<bits/stdc++.h>
using namespace std;

int t, ans = 0;
bool flag[100010] = {};
int n, a[200020] = {0};
int check()
{
    int sum = 0;
    int r = 0, b = 0;
    for(int i = 1; i <= n; i++)
    {
        if(flag[i])
        {
            if(r != a[i]) r = a[i];
            else sum += r, r = a[i];
        }
        else
        {
            if(b != a[i]) b = a[i];
            else sum += b, b = a[i];
        }
    }
    return sum;
}
void dfs(int step)
{
    if(step == n)
    {
        ans = max(ans, check());
        return;
    }
    dfs(step + 1);
    flag[step] = true;
    dfs(step + 1);
    flag[step] = false;
}
void Main()
{
    ans = 0;
    cin >> n;
    memset(flag, false, sizeof(flag));
    for(int i = 1; i <= n; i++) cin >> a[i];
    dfs(1);
    cout << ans << endl;
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        Main();
    }
    return 0;
}
