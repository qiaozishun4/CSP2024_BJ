#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    int arr[14] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68};

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        if(n < 14) cout << arr[n];
        else if(n % 7 == 0) {
            for(int i{0}; i < n / 7; i++) cout << 8;
        } else {
            cout << arr[n % 7 + 7];
            for(int i{1}; i < n / 7; i++) cout << 8;
        }

        cout << endl;
    }

    return 0;
}