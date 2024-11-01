#include<iostream>
using namespace std;
int t, n;
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n / 7; i++) {
            cout << 8;
        }
        cout << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
