#include <bits/stdc++.h>
using namespace std;

const int NR = 2e5 + 10;
int n, T, col[NR], a[NR], ans;

void check()
{
    int tmp = 0;
    for(int i = 2; i <= n; i++)
    {
        for(int j = i - 1; j >= 1; j--)
        {
            if(col[j] == col[i] && a[j] == a[i])
            {
                tmp += a[i];
                break;
            }
            else if(col[j] == col[i]) break;
        }
    }
    /*if(tmp == 18)
    {
        for(int i = 1; i <= n; i++)
        {
            cout << col[i] << " ";
        }
        cout << "\n";
    }*/
    ans = max(ans, tmp);
}

void dfs(int now)
{
    if(now > n)
    {
        check();
        return;
    }
    col[now] = 1;
    dfs(now + 1);
    col[now] = 0;
    dfs(now + 1);
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
            col[i] = 0;
        }
        dfs(1);
        cout << ans << "\n";
    }
    return 0;
}