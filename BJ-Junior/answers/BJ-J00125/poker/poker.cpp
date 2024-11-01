#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, cnt = 0;
string s;
map<string, ll> mp;
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> s;
        //if (mp[s] == 0) cnt++;
        mp[s]++;
    }
    cout << 52 - mp.size();
    return 0;
}
