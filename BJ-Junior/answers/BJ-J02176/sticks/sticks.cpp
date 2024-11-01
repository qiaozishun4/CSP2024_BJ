#include<bits/stdc++.h>
using namespace std;

int T, n, len;
int a[21] = {0, 0, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 808};
string ans;
string dp[2024];
string dp2[2024];

bool check(string a, string b)
{
    if(a.size() != b.size()) return a.size() < b.size();
    for(int i = 0; i < a.size(); i ++)
    {
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return 1;
}

void dfs(int step, string sum, int cnt)
{
    if(check(ans, sum)) return ;
    if(step <= len && cnt + 1 >= n) return ;
    if(step > len)
    {
        if(cnt == n && check(sum, ans)) ans = sum;
        return ;
    }
    for(int i = 2; i <= 7; i ++)
    {
        if(i == 6)
            if(step == 1) dfs(step + 1, sum + char(a[i]+'0'), cnt + i);
            else dfs(step + 1, sum + '0', cnt + i);
        else dfs(step + 1, sum + char(a[i]+'0'), cnt + i);
    }
}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        cin >> n;
        if(n == 1)
        {
            cout << -1;
            continue;
        }
        if(n % 7 == 0)
        {
            for(int i = 1; i <= n/7; i ++)
                cout << 8;
            cout << '\n';
            continue;
        }
        if(n%7 == 1)
        {
            cout << 10;
            n -= 8;
            for(int i = 1; i <= n/7; i ++)
                cout << 8;
            cout << '\n';
            continue;
        }
        len = (n+6)/7;
        for(int i = 1; i <= len; i ++) ans += "9";
        dfs(1, "", 0);
        cout << ans << '\n';
        //cout << a[n] << '\n';
    }
    return 0;
}
