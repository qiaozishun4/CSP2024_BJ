#include<bits/stdc++.h>
using namespace std;

int t;
int n;

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    for (int i = 1 ; i <= t ; i++) {
        cin >> n;
        if (n < 2) {
            cout << -1;
        }
    }
    return 0;
}
