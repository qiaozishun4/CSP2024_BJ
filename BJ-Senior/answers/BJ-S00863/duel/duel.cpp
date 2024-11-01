

#include <bits/stdc++.h>

using namespace std;

int _maxi;
int _hash[100009];
int _res = 0;

bool cmp(int one,int two) {
    return one < two;
}

int main () {
    int curInt;

    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

     cin >> _maxi;

    for(int i = 0; i < _maxi; i++) {
        cin >> curInt;
        _hash[curInt]++;
    }

    curInt = -1;

    for(int i = 0; i < 100005; i++) {
        if(curInt == -1 && _hash[i] != 0) {
            curInt = _hash[i];
            continue;
        }

        if(_hash[i] != 0) {
            if(curInt <= _hash[i]) {
                _res += curInt;
                curInt = _hash[i];
            }

            else{
                int cc = curInt;

                _res += _hash[i];
                curInt = cc - _hash[i] + _hash[i];
            }

        }
    }

    cout << _maxi - _res << endl;

    return 0;
}
