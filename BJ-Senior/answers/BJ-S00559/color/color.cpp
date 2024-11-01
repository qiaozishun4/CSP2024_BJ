#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5+10;
int T;
ll n;
ll a[N];
ll c[N];

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n;
        memset(c, 0, sizeof(c));
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = n; i >= 2; i--) {
            for (int j = i; j >= 1; j--) {
                if (i == j) continue;
                if (a[i] == a[j]) {
                    c[i] = a[i];
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += c[i];
        }
        cout << ans << "\n";
    }
}
