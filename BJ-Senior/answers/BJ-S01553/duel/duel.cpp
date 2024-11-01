#include <bits/stdc++.h>
using namespace std;

int const N = 1e5 + 10;
int n, a[N];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <= n;++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    priority_queue <int, vector<int>, greater<int> > t;
    t.push(a[1]);
    for (int i = 2;i <= n;++i) {
        if (a[i] > t.top()) {
            t.pop();
        }
        t.push(a[i]);
    }
    cout << t.size();
    return 0;
}
