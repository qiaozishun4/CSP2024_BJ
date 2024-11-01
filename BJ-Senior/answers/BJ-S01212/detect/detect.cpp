#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;

int t;

int n, m, L, V;

struct node {
    int d, v, a;
}p[MAX];

int mach[MAX];

int ans1 = 0;

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    cin >> t;

    while(t--) {

        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; i++) cin >> p[i].d >> p[i].v >> p[i].a;
        for(int i = 1; i <= m; i++) cin >> mach[i];

        ans1 = 0;
        for(int i = 1; i <= n; i++) {
            if(p[i].v > V && p[i].d <= mach[m]) ans1++;
        }
        if(ans1 == 0) cout << ans1 << " " << m << endl;
        else cout << ans1 << " " << m-1 << endl;
    }

    return 0;
}
