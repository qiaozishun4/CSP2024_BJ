#include<iostream>
using namespace std;
int t, n, ans[15] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88};
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n;
        if(n < 15) cout << ans[n] << endl;
        else {
            int remain = n / 7;
            if(n % 7 == 1) {
                cout << 10;
                remain--;
            }
            else if(n % 7 == 2) {
                cout << 1;
            }
            else if(n % 7 == 3) {
                cout << 200;
                remain -= 2;
            }
            else if(n % 7 == 4) {
                cout << 20;
                remain--;
            }
            else if(n % 7 == 5) {
                cout << 2;
            }
            else if(n % 7 == 6) {
                cout << 6;
            }
            for(int i = 0; i < remain; i++) cout << 8;
            cout << endl;
        }
    }
    return 0;
}
/*
0123456789
6255456376
*/