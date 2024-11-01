#include <iostream>

using namespace std;
int n;
int r;
int main () {
    freopen ("duel.in", "r", stdin);
    freopen ("duel.out", "w", stdout);
    cin >> n;
    int res = 0;
    while (n--) {
        cin >> r;
        if (n == 0) {
            return 0;
        }
        if (r != 0) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}