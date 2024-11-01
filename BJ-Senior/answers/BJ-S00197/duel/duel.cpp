#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
bool Cmp(ll one, ll two) {
    return one > two;
}
ll n;
ll r[100010];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    ll cc = n;
    sort(r + 1, r + 1 + n, Cmp);
    for(int i = 1; i <= n; i++) {
        if(r[i] == 0) {
            continue;
        }
        for(int j = i + 1; j <= n; j--) {
            if(r[j] < r[i]) {
                r[j] = 0;
                cc--;
                break;
            }
        }
    }
    cout << cc;
    return 0;
}
