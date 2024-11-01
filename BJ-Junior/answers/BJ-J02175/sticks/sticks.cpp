#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
ll n;
ll stick[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
ll count_stick(ll x)
{
    ll ans = 0;
    while(x)
    {
        ans += stick[x % 10];
        x /= 10;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 1)
        {
            cout << "-1\n";
            continue;
        }
        string ans;
        if(n % 6 == 1)
        {
            ans += "12";
            for(int i = 1; i < n / 6; i++)
                ans += "0";
        }
        if(n % 6 == 2)
        {
            ans += "1";
            for(int i = 1; i <= n / 6; i++)
                ans += "0";
        }
        if(n % 6 == 3)
        {
            ans += "7";
            for(int i = 1; i <= n / 6; i++)
                ans += "0";
        }
        if(n % 6 == 4)
        {
            ans += "4";
            for(int i = 1; i <= n / 6; i++)
                ans += "0";
        }
        if(n % 6 == 5)
        {
            ans += "2";
            for(int i = 1; i <= n / 6; i++)
                ans += "0";
        }
        if(n % 6 == 0)
        {
            if(n / 6 == 1)
                ans += "6";
            else
            {
                ans += "28";
                for(int i = 1; i < n / 6 - 1; i++)
                    ans += "0";
            }
        }
        sort(ans.begin(), ans.end());
        if(ans[0] == '0')
        {
            ll not0id = 0;
            while(ans[not0id] == '0')
                not0id++;
            swap(ans[0], ans[not0id]);
        }
        cout << ans << "\n";
    }
    return 0;
}