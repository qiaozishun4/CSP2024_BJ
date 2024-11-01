#include <bits/stdc++.h>
// long long freopen
using namespace std;
int const N = 1e3 + 10;
int n, m, k, x, y, d, t[N][N];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char a[N][N];

void Main() {
    stack <int> t;
    cin >> n;
    if (n == 1) {
        cout << -1 << endl;
        return;
    }
    int k = n / 7;
    while (k--) t.push(8);
    k = n / 7;
    int s = n % 7;
    if (s == 0) {
        while (!t.empty()) {
            cout << t.top();
            t.pop();
        }
        cout << endl;
        return;
    }
    if (s + k >= 2 && s <= 2) {
        k = 2 - s;
        for (int i = 1;i <= k;++i) t.pop();
        for (int i = 1;i <= k;++i) t.push(0);
        t.push(1);
    }
    else if (s + k >= 5 && s <= 5) {
        k = 5 - s;
        for (int i = 1;i <= k;++i) t.pop();
        for (int i = 1;i <= k;++i) t.push(0);
        t.push(2);
    }
    else if (s + k >= 4 && s <= 4) {
        k = 4 - s;
        for (int i = 1;i <= k;++i) t.pop();
        for (int i = 1;i <= k;++i) t.push(0);
        t.push(4);
    }

    else if (s == 1 && k == 0) {
        t.pop();
        t.push(6);
        t.push(1);
    }
    else if (s == 2) t.push(1);
    else if (s == 3) t.push(7);
    else if (s == 4) t.push(4);
    else if (s == 5) t.push(2);
    else if (s == 6) t.push(6);
    while (!t.empty()) {
        cout << t.top();
        t.pop();
    }
    cout << endl;
}

int main() {
    freopen("sticks.in","r", stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    while (T--) Main();
    return 0;
}

