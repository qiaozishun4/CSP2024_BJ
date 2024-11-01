#include<iostream>
using namespace std;
long long n, m, q, t, a[10010][10010];
long long b[10010][10010];
int main () {
    cin >> t;
    while (t--) {
        cin >> n >>m>>q;
        if (k>5&&k!=200000) {
            cout << 0;
            break;
        }
        for (int i=1;i<=n;i++)
            while (cin >> n) {
                b[n]++;
                if (b[n]>5) {
                    cout << 0;
                    break;
                }
            }
        cout << 1;
    }
    return 0;
}