#include <bits/stdc++.h>
using namespace std;
int t, n, a[200001], b[200001], c[200001], ans;
void g(int w) {
    for(int i = 1; i <= n; i++) {
        b[i] = w & 1;
        w /= 2;
    }
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> t;
    while(t--) {
        ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(long long w = 0; w < (n << 2); w++) {
            memset(c, 0, sizeof(c));
            g(w);
            int sum = 0;
            for(int i = 1; i <= n; i++) {
                for(int j = i-1; j > 0; j--) {
                    if(b[i] == b[j]) {
                        if(a[i] != a[j]) c[i] = 0;
                        else {
                            c[i] = a[i];
                            break;
                        }
                    }
                }
            }
            for(int i = 1; i <= n; i++) {
                sum += c[i];
            }
            ans = max(ans, sum);
        }
        cout << ans << endl;
    }
    return 0;
}