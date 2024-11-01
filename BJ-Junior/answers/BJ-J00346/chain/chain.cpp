#include <bits/stdc++.h>
using namespace std;
int T, n, k, q, l[100005], r, c;
vector<int> v[100005];
bool check() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= l[i]; i++)
            if (v[i][j] == 1)
                for (int l = j; l < j + k; l++)
                    if (v[i][l] == c)
                        return true;
    return false;
}
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n >> k >> q;
        bool hv = false;
        for (int i = 1; i <= n; i++) {
            cin >> l[i];
            v[i].clear();
            v[i].push_back(0);
            for (int j = 1; j <= l[i]; j++) {
                int s;
                cin >> s;
                if (s == 1)
                    hv = true;
                v[i].push_back(s);
            }
        }
        if (!hv) {
            cout << 0 << endl;
            continue;
        }
        while (q--) {
            cin >> r >> c;
            if (r == 1)
                if (check())
                    cout << 1 << endl;
                else
                    cout << 0 << endl;
            else
                cout << 1 << endl;
        }
    }
    return 0;
}
