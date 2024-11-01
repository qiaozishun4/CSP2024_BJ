#include<iostream>
using namespace std;
long long t, n;
int main () {
    cin >> t;
    while (t--) {
        cin >> n;
        if (n%7!=0||(n-1)%7!=0) cout << -1;
    }
    return 0;
}
