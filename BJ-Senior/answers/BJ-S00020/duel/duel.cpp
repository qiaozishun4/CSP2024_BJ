#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int a[MAXN];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    // queue<int> m;
    priority_queue<int, vector<int>, greater<int>> m;
    int cnt = n;
    for (int i = 1; i <= n; i++) {
        if (!m.empty()) {
            int f = m.top();
            if (a[f] < a[i]) {
                cnt--;
                m.pop();
            }
        }
        m.push(i);
    }

    cout << cnt << "\n";

    return 0;
}
