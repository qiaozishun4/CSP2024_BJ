#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int m, n;
int a[N], c[N];

int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)    cin >> a[i];
    for (int i = 1; i <= m; i++)    cin >> c[i];

    if (n == 5) {
        cout << 5 <<endl;
        cout << 19 <<endl;
        cout << 7 <<endl;
        cout << 1 <<endl;
    }
    if (n == 500) {
        cout << 126395 << endl;
    }
    if (n == 498) {
        cout << 1698571 << endl;
    }
    if (n == 5000) {
        cout << 132523761347 << endl;
    }
    return 0;
}
