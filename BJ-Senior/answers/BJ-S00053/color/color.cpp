#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 20;
int T, n, col[N];
LL a[N], ans;

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while(T--) {
        ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 1; i < (1<<n); i++) {
            LL sum = 0;
            for(int j = 1; j <= n; j++) {
                if ((i >> (n-j)) & 1) {
                    col[j] = 1;
                } else {
                    col[j] = 0;
                }
            }
            for(int j = 1; j <= n; j++) {
                for(int k = j-1; k >= 1; k--) {
                    if (col[k] == col[j]) {
                        if (a[k] == a[j]) sum += a[j];
                        break;
                    }
                }
            }
            ans = max(ans, sum);
        }
        cout << ans << endl;
    }
    return 0;
}
