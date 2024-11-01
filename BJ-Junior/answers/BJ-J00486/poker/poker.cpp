#include <bits/stdc++.h>
using namespace std;
#define int long long
map<string, bool> mp;
int n, cnt;
string s;
#undef int
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    #define int long long
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--) {
        cin >> s;
        mp[s] = true;
    }
    for (auto it : mp) cnt++;
    cout << 52 - cnt << "\n";
    return 0;
}