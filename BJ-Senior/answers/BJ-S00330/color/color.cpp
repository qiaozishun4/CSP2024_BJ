#include <iostream>
#include <cmath>
using namespace std;
const int mxn = 1000005;
int ans[mxn];
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    long long sum;
    int maxn;
    while (t--) {
        maxn = -1;
        sum = 0;
        int n;
        cin >> n;
        int a[n + 5];
        for (int i = 0; i < 1000005; i++) {
            ans[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ans[a[i]]++;
            maxn = max(maxn, a[i]);
        }
        for (int i = 0; i <= maxn; i++) {
            sum += i * (ans[i] - 1);
        }
        cout << sum << endl;
    }
    return 0;
}