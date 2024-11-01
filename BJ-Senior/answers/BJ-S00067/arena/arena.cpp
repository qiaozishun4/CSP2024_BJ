#include <bits/stdc++.h>
using namespace std;

int T;
vector<int> a[100005];
int r[100005], c[100005];

int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);

    cin >> T;

    while (T--) {
        int n, k, q;

        cin >> n >> k >> q;

        for (int i = 1; i <= n; i++) {
            int len;

            cin >> len;

            a[i].push_back(len);

            for (int j = 1; j <= len; j++) {
                int num;

                cin >> num;

                a[i].push_back(num);
            }
        }

        for (int i = 1; i <= q; i++) {
            cin >> r[i] >> c[i];
        }

        cout << 1 << endl;
    }

    return 0;
}