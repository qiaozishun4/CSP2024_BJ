

#include <iostream>
#include <fstream>

using namespace std;

//0-red, 1-blue

int _maxi = 0;
int _myArray[109];
int _myHash[109];

int FindAns () {
    int maxi = 1;
    int solo = 0;
    int res = 0;
    int sum = 0;

    for (int i = 0; i < _maxi; i++) {
        maxi *= 2;
    }

  //  cout << 1 << endl;
    for (int i = 0; i < maxi; i++) {
        solo = i;

        for (int m = 0; m < _maxi; m++) {
            _myHash[m] = solo % 2;
            solo /= 2;
        }
        bool _out = false;
        sum = 0;

        for (int m = 0; m < _maxi; m++) {
            for (int k = m - 1; k > -1; k--) {
                if (_myHash[k] == _myHash[m]) {
                    if (_myArray[k] == _myArray[m]) {
                        sum += _myArray[k];
                    }
                    break;
                }
            }
        }
        res = max(sum, res);
    }

    //cout << 1 << endl;
    return res;
}

void mwkldq () {
    int maxi = 0;

    ifstream inFile("color.in");
    ofstream outFile("color.out");

    inFile >> maxi;


    for (int i = 0; i < maxi; i++) {
        inFile >> _maxi;
        for (int m = 0; m < _maxi; m++) {
            inFile >> _myArray[m];
        }

        int res = FindAns();
        outFile << res << endl;
    }

    outFile.close();
    inFile.close();
}

int main () {

    mwkldq();

    return 0;
}
