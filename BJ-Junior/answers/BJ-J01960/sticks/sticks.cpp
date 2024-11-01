// sticks
#include <iostream>
#include <algorithm>
#include<cstring>

using namespace std;

const int NUM[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int arr[] = {8, 0, 6, 9, 2, 3, 5, 4, 7, 1};
void solve() {
    int n;
    cin >> n;
    if (n % 7 == 0) {
        for(int i = 1; i <= n / 7; i++) {
            cout<<8;
        }
        cout<<endl;
        return;
    } else if (n % 7 == 1) {
        if (n == 1) cout << -1 << endl;
        else {
            cout << 10;
            for (int i = 1; i <= (n-1)/7-1; i++) {
                cout << 8;
            }
            cout << endl;
        }
        return;
    }
}

int main() {
    freopen("sticks.out", "w", stdout);
    freopen("sticks.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) solve();
	return 0;
}