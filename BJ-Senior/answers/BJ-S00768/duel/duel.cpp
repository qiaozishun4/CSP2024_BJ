#include <bits/stdc++.h>
using namespace std;
int r[100005], a[100005];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    bool flag = 1;
    for (int i = 1;i <= n;i++)
    {
        cin >> r[i];
        a[i] = 1;
        if (r[i] > 2) flag = 0;
    }
    if (flag) {
        int sum = 0, sum2 = 0;
        for (int i = 1;i <= n;i++) {
            if (r[i] == 2) {
                sum++;
            }
            if (r[i] == 1) {
                sum2++;
            }
        }
        cout << max(sum, sum2) << endl;
        return 0;
    }
    sort(r + 1, r + n + 1);
    for (int i = 2;i <= n+1;i++) {
        for (int j = 1;j <= i;j++) {
            if (r[j] < r[i] && a[j] != -1 && a[i] != 0)
            {
                a[j] = -1;
                a[i] = 0;
            }
        }
    }
    int sum = 0;
    for (int i = 1;i <= n;i++) {
        if (a[i] != -1) sum++;
    }
    cout << sum << endl;
    /*for (int i = 1;i <= n;i++) {
        cout << r[i] << " ";
    }
    cout << endl;
    for (int i = 1;i <= n;i++) {
        cout << a[i] << " ";
    }*/
    return 0;
}
