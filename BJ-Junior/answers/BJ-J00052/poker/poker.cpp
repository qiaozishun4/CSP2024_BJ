#include <bits/stdc++.h>
using namespace std;

int n, ans = 52;
string a[107] = {};

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++) if (a[i] != a[i-1]) ans--;
    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}