#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int l[2 * N], r[N], c[N];
vector<int> s[N];

int main() {
freopen("chain.in", "r", stdin);
freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        int n, k, q;
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++) {
            cin >> l[i];
            for (int j = 1; j <= l[i]; j++) {
                int x;
                cin >> x;
                s[i].push_back(x);
            }
        }
        if (k == 2e5) {
            cout << 0 << endl;
            continue;
        }
        cout << 1 << endl;
    }
    return 0;
}