#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int a[N];

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t, n;
    cin >> t;
    while (t--) {
        int tt = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            tt += a[i];
        }
        cout << tt <<'\n';
    }
    return 0;
}
