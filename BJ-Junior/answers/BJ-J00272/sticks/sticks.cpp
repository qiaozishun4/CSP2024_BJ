#include <bits/stdc++.h>
using namespace std;
int n;
string ans = "99999999999999999";
int d[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
bool c(string x, string y)
{
    if(x.size() != y.size())
    {
        return x.size() < y.size();
    }
    for(int i = 0; i < x.size(); i++)
    {
        if(x[i] != y[i])
        {
            return x[i] < y[i];
        }
    }
    return 0;
}
void dfs(int step, string s)
{
if(step >= n)
{
    if(step == n)
    {
        if(c(s, ans) && s[0] != '0')
        {
            ans = s;
        }
    }
    return;
}
    for(int i = 0; i <= 9; i++)
    {
        if(i == 3 || i == 5 || i == 9 || (i == 6 && step > 0))
        {
            continue;
        }
        dfs(step + d[i], s + to_string(i));
    }
}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n % 7 == 0 && n >= 100)
        {
            for(int i = 1; i <= n / 7; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if(n % 7 == 1 && n >= 100)
        {
            int x = n / 7 - 1;
            cout << 10;
            for(int i = 1; i <= x; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else
        {
             ans = "99999999999999999";
             dfs(0, "");
             if(ans != "99999999999999999")
             {
                 cout << ans << endl;
             }
             else
             {
                cout << -1 << endl;
             }
        }
    }
    return 0;
}
