#include<iostream>
using namespace std;
int h[14] = {0,-1,1,7,4,2,6,8,10,18,22,20,28,68};
int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    for (int i=1;i<=t;i++) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << -1 << endl;
        } else if (n%7 == 0) {
            for (int j=1;j<=n/7;j++) {
                cout << 8;
            }
            cout << endl;
        } else if (n%7 == 1) {
            cout << 10;
            for (int j=1;j<=n/7-1;j++) {
                cout << 8;
            }
            cout << endl;
        } else {
            if (n < 14) {
                cout << h[n];
            } else {
                int w = n/7-1;
                cout << h[n-(w*7)];
                for (int j=1;j<=w;j++) {
                    cout << 8;
                }
            }
            cout << endl;
        }
    }
    return 0;
}
