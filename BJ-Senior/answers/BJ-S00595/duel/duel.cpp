#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100001];
//int b[100001];
//priority_queue<int> q;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int b = lower_bound(a + 1, a + n + 1, a[i]) - a - 1;
        if (b > cnt) {
            cnt++;
        }
    }
    cout << n - cnt << endl;
    return 0;
}
