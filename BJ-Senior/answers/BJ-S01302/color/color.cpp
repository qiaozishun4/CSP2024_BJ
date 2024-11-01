#include<iostream>
#include<cstring>
using namespace std;

int t, n, ans, a[100005];
bool b[100005];

int f()
{
    int lsta = 0, lstb = 0, cnt = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(b[i])
        {
            if(a[i] == a[lsta])
            {
                cnt += a[i];
            }
            lsta = i;
        }
        else
        {
            if(a[i] == a[lstb])
            {
                cnt += a[i];
            }
            lstb = i;
        }
    }
    return cnt;
}

void dfs(int dep)
{
    if(dep == n + 1)
    {
        ans = max(ans, f());
        return ;
    }

    b[dep] = 1;
    dfs(dep + 1);

    b[dep] = 0;
    dfs(dep + 1);

    return ;
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    ios::sync_with_stdio(false);

    cin >> t;

    while(t --)
    {
        ans = 0;
        memset(a, 0, sizeof a);
        memset(b, false, sizeof b);

        cin >> n;
        for(int i = 1; i <= n; i ++)
        {
            cin >> a[i];
        }
        dfs(1);

        cout << ans << endl;
    }

    return 0;
}