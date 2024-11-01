#include <bits/stdc++.h>
using namespace std;
int n, a[62];
int sum;
int main () {
    freopen ("poker.in", "r", stdin);
    freopen ("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        if (n != 0){
            sum++;
        }
        else {
            sum = 0;
        }
    }
    cout << 52 - sum << endl;
    return 0;
}
