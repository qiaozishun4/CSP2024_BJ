

#include <bits/stdc++.h>

using namespace std;

int T;
int _maxi;
int _array[200009];
int _res = 0;
string _myStr;

int main () {
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    cin >> T;

    while(T--) {
        _res = -1;
        _myStr = "0";

        cin >> _maxi;

        for(int i = 0; i < _maxi; i++) {
            cin >> _array[i + 1];
            _myStr += '0';
        }

        while(_myStr[0] != '1') {
            int cc = 0;

            for(int i = 1; i < _myStr.length(); i++) {
                for(int m = i + 1; m < _myStr.length(); m++) {
                    if(_myStr[m] == _myStr[i]) {
                        if(_array[i] == _array[m]) {
                            cc += _array[i];
                        }

                        break;
                    }
                }
            }

            if(cc > _res) {
                _res = cc;
            }

            _myStr[_myStr.length() - 1]++;


            for(int i = _myStr.length() - 1; i > -1; i--) {
                if(_myStr[i] > '1') {
                    _myStr[i] = '0';
                    _myStr[i - 1]++;
                }

                else{
                    break;
                }
            }
        }

        cout << _res << endl;
    }

    return 0;
}
