#include <bits/stdc++.h>
using namespace std;
set<string> s;
int main() {
        freopen("poker.in", "r", stdin);
        freopen("poker.out", "w", stdout);
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
                string p;
                cin >> p;
                s.insert(p);
        }
        cout << 52 - s.size() << "\n";
        return 0;
}
