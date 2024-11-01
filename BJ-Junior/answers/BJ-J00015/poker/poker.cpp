#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        mp[s]++;
    }

    cout << max(0, 52 - (int)mp.size()) << "\n";

    return 0;
}
