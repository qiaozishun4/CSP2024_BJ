#include <iostream>
#include <map>
#define int long long
using namespace std;

map<string, bool> mp;
string hs[] = {"", "D", "C", "H", "S"};
string ds[] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};

signed main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        mp[s] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= 4; ++i){
        for (int j = 1; j <= 13; ++j) {
            string s = hs[i] + ds[j];
            if (mp[s]) continue;
            ++ans;
        }
    }
    cout << ans;
    return 0;
}
