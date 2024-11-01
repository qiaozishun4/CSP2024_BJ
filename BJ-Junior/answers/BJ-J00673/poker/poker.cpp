#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    set<string> se;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        se.insert(s);
    }
    cout << 52 - (int)se.size() << "\n";
    return 0;
}

