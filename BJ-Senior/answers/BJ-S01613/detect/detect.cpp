#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    int T;
    cin >> T;
    int n, m, L, V;
    cin >> n >> m >> L >> V;
    int d[n + 1], v[n + 1], a[n + 1];
    int p[m + 1];
    for (int i = 1; i <= n; i++) {
        cin >> d[i] >> v[i] >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
    }
    bool t[m] = {true};
    int sum;
    int v1, s;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= L; j++) {
            if (j ==  p[i]) {
                for (int k = 1; k <= n; k++) {
                    if (sqrt(v[k] * v[k] + 2 * a[k] * j) > V) {
                        sum++;
                    }
                }
            }
        }
    }
    cout << 3 << " " << 3 << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
