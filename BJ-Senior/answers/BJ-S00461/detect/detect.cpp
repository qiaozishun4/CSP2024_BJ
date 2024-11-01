

#include <iostream>
#include <set>

using namespace std;

int _n, _m;
long long _l, _v;
long long _car[100009][3], _p[100009];
int _r1, _mn[100009], _r2;
set<int> _se;

int main () {
    int T, l, r, mid, di, ans;

    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T--) {
        cin >> _n >> _m >> _l >> _v;

        for (int i = 1; i <= _n; i++) {
            cin >> _car[i][0] >> _car[i][1] >> _car[i][2];
        }

        for (int i = 1; i <= _m; i++) {
            cin >> _p[i];
        }

        _r1 = 0;

        for (int i = 1; i <= _m; i++) {
            _mn[i] = _m + 1;
        }

        for (int i = 1; i <= _n; i++) {
            l = 1;
            r = _m;
            di = _m + 1;

            while (l <= r) {
                mid = (l + r) / 2;

                if (_p[mid] < _car[i][0]) {
                    l = mid + 1;
                }

                else {
                    di = mid;
                    r = mid - 1;
                }
            }

            if (di == _m + 1) {
                continue;
            }

            else if (_car[i][2] > 0) {
                l = di;
                r = _m;
                ans = _m + 1;

                while (l <= r) {
                    mid = (l + r) / 2;

                    if (2 * _car[i][2] * (_p[mid] - _car[i][0]) + _car[i][1] * _car[i][1] > _v * _v) {
                        ans = mid;
                        r = mid - 1;
                    }

                    else {
                        l = mid + 1;
                    }
                }

                if (ans != _m + 1) {
                    _r1++;
                    _mn[ans] = min(_mn[ans], _m);
                }
            }

            else if (_car[i][2] < 0) {
                l = di;
                r = _m;
                ans = di - 1;

                while (l <= r) {
                    mid = (l + r) / 2;

                    if (2 * _car[i][2] * (_p[mid] - _car[i][0]) + _car[i][1] * _car[i][1] > _v * _v) {
                        ans = mid;
                        l = mid + 1;
                    }

                    else {
                        r = mid - 1;
                    }
                }

                if (ans != di - 1) {
                    _r1++;
                    _mn[di] = min(_mn[di], ans);
                }
            }

            else {
                if (_car[i][1] > _v) {
                    _r1++;
                    _mn[di] = min(_mn[di], _m);
                }
            }
        }

        cout << _r1 << ' ';

        _r2 = _m;

        for (int i = 1; i <= _m; i++) {
            if (_mn[i] != _m + 1) {
                _se.insert(_mn[i]);
            }

            if (!_se.empty() && (*_se.begin()) == i) {
                _r2--;
                _se.clear();
            }
        }

        cout << _r2 << endl;
    }

    return 0;
}
