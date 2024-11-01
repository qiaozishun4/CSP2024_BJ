#include <iostream>

using namespace std;

int r[100005], pre[100005];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    int mx = 0, x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        r[x]++;
        mx = max(mx, x);
    }
    for (int i = 1; i <= mx; i++) {
        pre[i] = pre[i - 1] + r[i];
    }
    int km = 0;
    for (int i = 2; i <= mx; i++) {
        if (!r[i]) continue;
        if (r[i] >= pre[i - 1] - km) km = pre[i - 1];
        else km += r[i];
    }
    cout << n - km << endl;
    return 0;
}