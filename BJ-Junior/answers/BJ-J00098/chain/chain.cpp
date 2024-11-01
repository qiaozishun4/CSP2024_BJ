#include <bits/stdc++.h>
using namespace std;

long long t, n, k, q, r, c;
int num[1005][2005];
bool is = 0;
int l[200005];

void jl (vector <int> a, int x, int i) {
    if (is) {
        return;
    }
    if (a.size() < 2) {
        return;
    }
    if (x >= r) {
        if (a[a.size() - 1] == c) {
            is = 1;
            return;
        }
        return;
    }
    for (int q = 1; q <= n; ++q) {
        for (int p = 1; p <= l[q]; ++p) {
            if (q == i) {
                break;
            } else {
                if (num[q][p] == a[a.size() - 1]) {
                    vector <int> v;
                    for (int j = p; j < p + k && j <= l[q]; ++j) {
                        v.push_back(num[q][j]);
                        jl(v, x + 1, q);
                    }
                }
            }
        }
    }

}

int main () {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    for (int z = 1; z <= t; ++z) {
        cin >> n >> k >> q;
        for (int i = 1; i <= n; ++i) {
            cin >> l[i];
            for (int j = 1; j <= l[i]; ++j) {
                cin >> num[i][j];
            }
        }
        for (int i = 1; i <= q; ++i) {
            cin >> r >> c;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= l[i]; ++j) {
                    if (num[i][j] == 1) {
                        vector <int> x;
                        for (int q = j; q < j + k; ++q) {
                            x.push_back(num[i][q]);
                            jl(x, 1, i);
                        }
                    }
                }
            }
            if (is) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
            is = 0;
        }
    }
    return 0;
}
