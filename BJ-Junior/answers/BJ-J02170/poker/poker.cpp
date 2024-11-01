#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, cnt = 0;
    cin >> n;
    string s = "D";
    mp[s + 'A'] = 0;
    mp[s + '2'] = 0;
    mp[s + '3'] = 0;
    mp[s + '4'] = 0;
    mp[s + '5'] = 0;
    mp[s + '6'] = 0;
    mp[s + '7'] = 0;
    mp[s + '8'] = 0;
    mp[s + '9'] = 0;
    mp[s + 'T'] = 0;
    mp[s + 'J'] = 0;
    mp[s + 'Q'] = 0;
    mp[s + 'K'] = 0;
    s = "C";
    mp[s + 'A'] = 0;
    mp[s + '2'] = 0;
    mp[s + '3'] = 0;
    mp[s + '4'] = 0;
    mp[s + '5'] = 0;
    mp[s + '6'] = 0;
    mp[s + '7'] = 0;
    mp[s + '8'] = 0;
    mp[s + '9'] = 0;
    mp[s + 'T'] = 0;
    mp[s + 'J'] = 0;
    mp[s + 'Q'] = 0;
    mp[s + 'K'] = 0;
    s = "H";
    mp[s + 'A'] = 0;
    mp[s + '2'] = 0;
    mp[s + '3'] = 0;
    mp[s + '4'] = 0;
    mp[s + '5'] = 0;
    mp[s + '6'] = 0;
    mp[s + '7'] = 0;
    mp[s + '8'] = 0;
    mp[s + '9'] = 0;
    mp[s + 'T'] = 0;
    mp[s + 'J'] = 0;
    mp[s + 'Q'] = 0;
    mp[s + 'K'] = 0;
    s = "S";
    mp[s + 'A'] = 0;
    mp[s + '2'] = 0;
    mp[s + '3'] = 0;
    mp[s + '4'] = 0;
    mp[s + '5'] = 0;
    mp[s + '6'] = 0;
    mp[s + '7'] = 0;
    mp[s + '8'] = 0;
    mp[s + '9'] = 0;
    mp[s + 'T'] = 0;
    mp[s + 'J'] = 0;
    mp[s + 'Q'] = 0;
    mp[s + 'K'] = 0;
    for (int i = 1; i <= n; i++) {
        string x;
        cin >> x;
        mp[x]++;
    }
    for (auto p : mp) {
        if (!p.second) cnt++;
    }
    cout << cnt;
    return 0;
}
