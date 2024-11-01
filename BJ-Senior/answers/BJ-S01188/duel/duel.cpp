#include <bits/stdc++.h>
using namespace std;

int n, x, cnt;
vector<int> r;
int a[100005];

bool cmp(int x, int y) {
    return x > y;
}

bool check() {
    for (int i = 0; i < r.size(); i++) {
        if (a[i] == 0) return 0;
    }
    return 1;
}

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        r.push_back(x);
    }
    sort(r.begin(), r.end(), cmp);
    //while (!check()) {
    for (int i = r.size() - 1; i >= 0; i--) {
        if (r.size() == cnt) break;
        if (r[i] > r[r.size() - 1] && a[i] == 0) {
            a[i] = 1;
            cnt++;
            r.pop_back();
        }
    }
    //}
    //for (int i = 0; i < r.size(); i++) {
    //    cout << r[i] << "\n";
    //}
    cout << r.size();

    return 0;
}
