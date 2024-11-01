#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    map<char, ll> m = {
        { 'D', 1 },
        { 'C', 2 },
        { 'H', 3 },
        { 'S', 4 },
        { 'A', 1 },
        { '2', 2 },
        { '3', 3 },
        { '4', 4 },
        { '5', 5 },
        { '6', 6 },
        { '7', 7 },
        { '8', 8 },
        { '9', 9 },
        { 'T', 10 },
        { 'J', 11 },
        { 'Q', 12 },
        { 'K', 13 }
    };
    ll n, cnt = 0;
    char x, y;
    bool a[10][20] = {};
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> x >> y;
        a[m[x]][m[y]] = 1;
    }
    for (ll i = 1; i <= 4; i++) {
        for (ll j = 1; j <= 13; j++) {
            cnt += !a[i][j];
        }
    }
    cout << cnt;

    return 0;
}
