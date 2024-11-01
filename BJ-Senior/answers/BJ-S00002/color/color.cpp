#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1E5 + 5;
int a[N];
int c[N];
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int maxn = -1;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(maxn < a[i]) {
                maxn = a[i];
            }
        }
        int cnt[maxn + 1];
        for(int i = 1; i <= maxn; i++) {
            cnt[i] = 0;
        }
        cnt[a[1]]++;
        unsigned long long ans = 0;
        for(int i = 2; i <= n; i++) {
            if(cnt[a[i]] != 0) {
                ans += a[i];
            }
            cnt[a[i]]++;
        }
        cout << ans << endl;
    }
    return 0;
}
