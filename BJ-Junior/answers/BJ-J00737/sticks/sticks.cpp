

#include <bits/stdc++.h>

using namespace std;

int _resArray[109];
int _myArray[109];
int _maxi = 0;

int NumToSticks (int num) {
    int res = 0;
    while (num != 0) {
        if (num % 10 == 0) {
            res += 6;
        }
        if (num % 10 == 1) {
            res += 2;
        }
        if (num % 10 == 2) {
            res += 5;
        }
        if (num % 10 == 3) {
            res += 5;
        }
        if (num % 10 == 4) {
            res += 4;
        }
        if (num % 10 == 5) {
            res += 5;
        }
        if (num % 10 == 6) {
            res += 6;
        }
        if (num % 10 == 7) {
            res += 3;
        }
        if (num % 10 == 8) {
            res += 7;
        }
        if (num % 10 == 9) {
            res += 6;
        }

        num = num / 10;
    }

    return res;
}

bool FullList () {
    for (int i = 0; i < _maxi; i++) {
        if (_resArray[i] == 2147483647) {
            //cout << "!!!" << i << endl;

            return true;
        }
    }

    return false;
}

int main () {
    int biggest = 0;
    int solo = 0;

    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    cin >> _maxi;

    for (int i = 0; i < _maxi; i++) {

        cin >> _myArray[i];

        _resArray[i] = 2147483647;

        if (_myArray[i] == 0 || _myArray[i] == 1) {

            _resArray[i] = -1;
        }
    }

    while (FullList()) {
        solo++;

        //cout << solo << endl;

        for (int i = 0; i < _maxi; i++) {
            if (NumToSticks(solo) == _myArray[i] && solo < _resArray[i]) {

                _resArray[i] = solo;
            }
        }
    }

    for (int i = 0; i < _maxi; i++) {

        cout << _resArray[i] << endl;
    }

    return 0;
}