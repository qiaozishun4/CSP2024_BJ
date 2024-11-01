#include <bits/stdc++.h>
using namespace std;
int n;
string s;
set<string> se;
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    while(n--) {
        cin >> s;
        se.insert(s);
    }
    cout << 52-se.size();
    return 0;
}
