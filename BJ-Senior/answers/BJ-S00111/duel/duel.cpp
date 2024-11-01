#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 5;
ll n, Max = -1e9;
ll r[maxn], mp[maxn];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >>r[i];
        mp[r[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        Max = max(Max, mp[r[i]]);
    }
    for (int i = 1; i <= n; i++) {
        if (mp[r[i]] == Max) {
            cout << mp[r[i]];
            return 0;
        }
    }
    return 0;
}
