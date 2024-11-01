#include <bits/stdc++.h>
using namespace std;
#define int long long

map<string, int> mp;
signed main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    cout << 52 - mp.size() << endl;
    return 0;
}
