#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
map <string, ll> mp;
// set <string> s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string poker;
        cin >> poker;
        mp[poker]++;
        // s.insert(poker);
    }
    cout << 52 - mp.size();
    // cout << 52 - s.size();
    return 0;
}