#include <bits/stdc++.h>
using namespace std;
long long a[100010];
long long vis[100010];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (long long i = 1; i <= n; i++) {
        if (vis[i] != 2 && vis[i] != 1) {
            for (long long j = 1; j < i; j++) {
                if (a[i] > a[j] && vis[j] != 1) {
                    vis[i] = 2;
                    vis[j] = 1;
                    break;
                }
            }
        }
    }
    long long cnt = 0;
    for (long long i = 1; i <= n; i++) {
        if (vis[i] != 1) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
