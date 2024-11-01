#include <iostream>
using namespace std;
int T, n;
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n;
        if(n%7==0) {
            for(int i=1; i<=n/7; i++) {
                cout << 8;
            }
            cout << endl;
        }
        else {
            if(n==1)cout << -1 << endl;
            n -= 8;
            cout << 10;
            for(int i=1; i<=n/7; i++) {
                cout << 8;
            }
            cout << endl;
        }
    }
    return 0;
}
