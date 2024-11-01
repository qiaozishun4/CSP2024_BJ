#include <iostream>
using namespace std;
long long t, n;
int ans[100005];
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    for(long long i = 0; i < 100005; i++) {
        ans[i] = -1;
    }
    ans[2] = 1;
    ans[3] = 7;
    ans[4] = 4;
    ans[5] = 2;
    ans[6] = 6;
    ans[7] = 8;
    ans[8] = 16;
    ans[9] = 18;
    ans[10] = 22;
    ans[11] = 20;
    ans[12] = 28;
    ans[13] = 80;
    ans[14] = 88;
    ans[15] = 180;
    ans[16] = 188;
    ans[17] = 228;
    ans[18] = 208;
    ans[19] = 288;
    ans[20] = 688;

    for(long long i = 0; i < t; i++) {
        cin >> n;
        if(n % 7 == 0) {
            for(long long j = 0; j < n / 7; j++) {
                cout << 8;
            }
            cout << endl;
        }
        else {
            cout << ans[n] << endl;
        }
    }
    return 0;
}
