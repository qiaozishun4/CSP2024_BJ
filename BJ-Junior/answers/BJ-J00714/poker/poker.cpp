#include <bits/stdc++.h>
using namespace std;
set<string> S;
int n;
string s;
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    while(n--) {
        cin >> s;
        S.insert(s);
    }
    cout << 52 - S.size() << endl;
    return 0;
}
