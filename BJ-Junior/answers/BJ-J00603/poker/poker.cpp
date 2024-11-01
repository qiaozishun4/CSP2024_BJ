#include <bits/stdc++.h>
using namespace std;
const int N = 100;
typedef long long ll;
ll n;
string s[N];
int main()
{
    freopen ("poker.in", "r", stdin);
    freopen ("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    sort (s + 1, s + 1 + n);
    string op = "";
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (op == s[i]) continue;
        op = s[i];
        ans ++;
    }
    cout << 52 - ans;
    return 0;
}