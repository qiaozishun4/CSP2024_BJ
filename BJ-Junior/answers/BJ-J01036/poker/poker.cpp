

#include <bits/stdc++.h>

using namespace std;

int _maxi;
vector<string> _myList;
int _res = 0;

int main () {
    string curStr;
    bool flag;

    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin >>_maxi;

    for(int i = 0; i < _maxi; i++) {
        cin >> curStr;
        _myList.push_back(curStr);
    }

    for(int i = 0; i < _myList.size(); i++) {
        flag = true;

        for(int m = 0; m < i; m++) {
            if(_myList[i] == _myList[m]) {
                flag = false;
                break;
            }
        }

        if(flag) {
            _res++;

        }
    }

    cout << 52 - _res <<endl;

    return 0;
}
