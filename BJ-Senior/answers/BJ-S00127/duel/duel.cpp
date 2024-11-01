#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100000 + 5;
int n;
int a[N];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int l = 1, r = 2;
    while (l <= n && r <= n) {
        if (a[r] > a[l]) {
            l++;
        }
        r++;
    }
    cout << n - l + 1 << endl;
    return 0;
}
