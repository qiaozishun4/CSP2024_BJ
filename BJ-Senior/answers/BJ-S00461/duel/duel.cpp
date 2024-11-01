

#include <iostream>
#include <algorithm>

using namespace std;

int _n, _r[100009], _res;

int main () {
    int p;

    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> _n;

    for (int i = 1; i <= _n; i++) {
        cin >> _r[i];
    }

    sort(_r + 1, _r + _n + 1);

    p = _n;
    _res = _n;

    for (int i = _n; i >= 1; i--) {
        while (p >= 1 && _r[i] <= _r[p]) {
            p--;
        }

        if (p == 0) {
            break;
        }

        _res--;
        p--;
    }

    cout << _res << endl;

    return 0;
}
