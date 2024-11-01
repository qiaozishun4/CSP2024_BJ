#include <iostream>
using namespace std;

int table[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void solve(int n) {
    if (n < 2) {
        cout << -1 << '\n';
        return;
    }
    if (n % 7 == 0) {
        int x = n / 7;
        while (x) {
            cout << 8;
            --x;
        } cout << '\n';
        return;
    } else if (n % 7 == 1) {
        int x = n / 7;
        cout << 1;
        while (x) {
            cout << 8;
            --x;
        } cout << '\n';
        return;
    }
}

int main(int argc, char const *argv[]) {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    //
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        solve(t);
    }
    //
    fclose(stdin);
    fclose(stdout);
    return 0;
}
