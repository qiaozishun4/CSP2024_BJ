#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 1;
    int i = 0;
    while (i < n) {
        int tmp = a[i];
        int cnt = 0;
        while (i < n && a[i] == tmp) {
            i++;
            cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}