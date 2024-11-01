

#include <bits/stdc++.h>

using namespace std;

struct Car{
    int _road;
    int _speed;
    int _add;
    long double _starti,_endi;
};

int T;
vector<Car> _myList;
vector<int> _checkList;
vector<int> _carList[100009];
int _res = 0;

bool cmp(vector<int> one,vector<int> two) {
    return one.size() < two.size();
}

int main () {
    int n,m,L,V;
    Car solo;
    int curInt;

    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    cin >> T;

    while(T--) {
        _myList.clear();
        _checkList.clear();
        _res = 0;

        cin >> n >> m >> L >> V;

        for(int i = 0; i < n; i++) {
            cin >> solo._road >> solo._speed >> solo._add;

            if(solo._speed > V && solo._add >= 0) {
                solo._starti = solo._road;
                solo._endi = 100009;
                _myList.push_back(solo);
                continue;
            }

            if(solo._speed <= V && solo._add <= 0) {
                solo._starti = 100009;
                solo._endi = solo._road;
                _myList.push_back(solo);
                continue;
            }

            if(solo._add > 0) {
                solo._starti = max((V * V - solo._speed * solo._speed) / (2 * solo._add) , solo._road);
                solo._endi = 100009;
                _myList.push_back(solo);
            }

            else{
                solo._starti = solo._road;
                solo._endi = (V * V - solo._speed * solo._speed) / (2 * solo._add);
                _myList.push_back(solo);
            }
        }

        for(int i = 0; i < m; i++) {
            cin >> curInt;
            _checkList.push_back(curInt);
        }

        for(int i = 0; i < _myList.size(); i++) {
            solo = _myList[i];
            for(int m = 0; m < _checkList.size(); m++) {
                if(solo._starti <= _checkList[m] && solo._endi >= _checkList[m]) {
                    _res++;
                    _carList[i].push_back(m);
                }
            }
        }

        cout << _res << endl;

        sort(_carList,_carList + n,cmp);

        cout << _res << endl;
    }

    return 0;
}
