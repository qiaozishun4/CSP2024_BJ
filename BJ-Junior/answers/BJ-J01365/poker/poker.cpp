#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int n;
unordered_map<string, int> mp;

signed main () {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string s;

        cin >> s;

        mp[s]++;
    }

    int t = 0;
    for (auto it : mp) {
        t++;
    }

    cout << 52 - t << endl;

    return 0;
}
