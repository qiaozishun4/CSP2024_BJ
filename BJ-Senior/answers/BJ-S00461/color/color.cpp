

#include <iostream>
#include <cstring>

using namespace std;

int _n;
long long _a[200009];
long long _f[200009], _mx[1000009], _res;

int main () {
    int T;
    long long bothadd, allmx;

    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    cin >> T;

    while (T--) {
        cin >> _n;

        for (int i = 1; i <= _n; i++) {
            cin >> _a[i];
        }

        bothadd = 0;
        allmx = 0;
        memset(_f, 0, sizeof(_f));
        memset(_mx, 0xf3, sizeof(_mx));

        for (int i = 1; i <= _n; i++) {
            _f[i] = max(allmx, _mx[_a[i + 1]] + _a[i + 1]);

            if (_a[i] == _a[i + 1]) {
                bothadd += _a[i + 1];
                _f[i] -= _a[i + 1];
            }

            _mx[_a[i]] = max(_mx[_a[i]], _f[i]);
            allmx = max(allmx, _f[i]);
        }

        _res = 0;

        for (int i = 1; i < _n; i++) {
            _res = max(_res, _f[i] + bothadd);
        }

        cout << _res << endl;
    }

    return 0;
}
