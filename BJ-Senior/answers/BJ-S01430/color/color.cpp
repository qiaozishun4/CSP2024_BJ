#include <iostream>
using namespace std;
int main()
{
    int T;
    int n[100000000];
    int a[100000000];
    int ans = 0;
    freopen("color.in", "r", stdin);
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n[i];
        for (int j = 0; j < n[i]; j++) {
            cin >> a[j];
        }
    }
    for (int i = 0; i < T; i++) {
        if (a[i] != a[i - 1] && a[i] != a[i + 1]) {
            ans += a[i];
        }
    }
    freopen("color.out", "w", stdout);
    cout << ans;
    return 0;
}
