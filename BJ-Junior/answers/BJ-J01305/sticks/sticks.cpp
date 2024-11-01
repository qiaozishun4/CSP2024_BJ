#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, cnt = 0;
string ans = "";
int a[20] = {0, 6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string minx(string x, string y)
{
    if(x.size() < y.size())
        return x;
    else if(y.size() < x.size())
        return y;
    for(int i = 0; i < x.size(); i++)
    {
        if(x[i] < y[i])
            return x;
        else if(x[i] > y[i])
            return y;
    }
    return x;
}
void dfs(int step, string s, int sum)
{
    if(sum > n)
        return;
    if(sum == n)
    {
        if(ans == "")
            ans = s;
        else
            ans = minx(ans, s);
        return;
    }
    for(int i = 1; i <= 10; i++)
    {
        if(step == 1 && i == 1)
            continue;
        char c = '0' + i - 1;
        dfs(step + 1, s + c, sum + a[i]);
    }
}
signed main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 1)
        {
            cout << -1 << endl;
            continue;
        }
        if(n <= 20)
        {
            ans = "";
            dfs(1, "", 0);
            if(ans == "")
                cout << -1 << endl;
            else
                cout << ans << endl;
            continue;
        }
        if(n % 7 == 1)
        {
            cout << 10;
            for(int i = 1; i <= (n - 1) / 7 - 1; i++)
                cout << 8;
            cout << endl;
        }
        else if(n % 7 == 2)
        {
            cout << 1;
            for(int i = 1; i <= (n - 2) / 7; i++)
                cout << 8;
            cout << endl;
        }
        else if(n % 7 == 3)
        {
            cout << 200;
            for(int i = 1; i <= (n - 3) / 7 - 2; i++)
                cout << 8;
            cout << endl;
        }
        else if(n % 7 == 4)
        {
            cout << 20;
            for(int i = 1; i <= (n - 4) / 7 - 1; i++)
                cout << 8;
            cout << endl;
        }
        else if(n % 7 == 5)
        {
            cout << 2;
            for(int i = 1; i <= (n - 5) / 7; i++)
                cout << 8;
            cout << endl;
        }
        else if(n % 7 == 6)
        {
            cout << 6;
            for(int i = 1; i <= (n - 6) / 7; i++)
                cout << 8;
            cout << endl;
        }
        else
        {
            for(int i = 1; i <= n / 7; i++)
                cout << 8;
            cout << endl;
        }
    }
    return 0;
}
