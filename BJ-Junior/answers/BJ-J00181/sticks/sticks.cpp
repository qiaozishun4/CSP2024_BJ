#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans = -1;
int g[100] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
void dfs(int cnt, int op, long long x, bool f)
{
    if(cnt == 0)
    {
        if(ans == -1) ans = x;
        ans = min(ans, x);
        return ;
    }
    if(cnt >= 6 && f)
    {
        dfs(cnt - 6, op, x * 10, f);
    }
    for(int i = op; i <= 9; i++)
    {
        if(cnt >= g[i])
        {
            dfs(cnt - g[i], i, x * 10 + i, 0);
        }
    }

}
signed main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ans = -1;
        int n;
        cin >> n;
        if(n <= 38)
        {
            for(int i = 1; i <= 9; i++)
            {
                if(n >= g[i])
                {
                    dfs(n - g[i], i, i, 1);
                }
            }
            cout << ans << endl;
        }
        else if(n % 7 == 0)
        {
            while(n)
            {
                cout << 8;
                n -= 7;
            }
            cout << endl;
        }
        else if(n % 7 == 1)
        {
            cout << 10;
            n -= 8;
            while(n)
            {
                cout << 8;
                n -= 7;
            }
            cout << endl;
        }
        else if(n % 7 == 2)
        {
            cout << 1;
            n -= 2;
            while(n)
            {
                cout << 8;
                n -= 7;
            }
        }
        else if(n % 7 == 3)
        {
            cout << 200;
            n -= 17;
            while(n)
            {
                cout << 8;
                n -= 7;
            };
        }
        else if(n % 7 == 4)
        {
            cout << 20;
            n -= 11;
            while(n)
            {
                cout << 8;
                n -= 7;
            }
        }
        else if(n % 7 == 5)
        {
            cout << 2;
            n -= 5;
            while(n)
            {
                cout << 8;
                n -= 7;
            }
        }
        else if(n % 7 == 6)
        {
            cout << 6;
            n -= 6;
            while(n)
            {
                cout << 8;
                n -= 7;
            }
        }
    }
    return 0;
}
//Y#C*GF@24
