#include <bits/stdc++.h>
using namespace std;
set<string> s;
int n;
string ss;
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ss;
        s.insert(ss);
    }
    cout << 52 - s.size();
    return 0;
}
