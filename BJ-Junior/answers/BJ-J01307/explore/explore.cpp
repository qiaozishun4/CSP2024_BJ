

#include <iostream>
#include <fstream>

using namespace std;

struct Place {
    int _line;
    int _cell;
};

int _lineM = 0; // line Maxi
int _cellM = 0; // cell Maxi
int _optNum = 0;
int _curDir = 0;
Place _curPlace;
int _myMap[1009][1009];
int _myHash[1009][1009];

void ParseIn () {
    //nothing
}

void FillHash () {
    for (int i = 1; i < _lineM + 1; i++) {
        for (int m = 1; m < _cellM + 1; m++) {
            _myMap[i][m] = 0;
            _myHash[i][m] = 0;
        }
    }
}

Place Move () {
    Place res;

    if (_curDir == 0) {
        res._line = _curPlace._line;
        res._cell = _curPlace._cell + 1;
    }
    if (_curDir == 1) {
        res._line = _curPlace._line + 1;
        res._cell = _curPlace._cell;
    }
    if (_curDir == 2) {
        res._line = _curPlace._line;
        res._cell = _curPlace._cell - 1;
    }
    if (_curDir == 3) {
        res._line = _curPlace._line - 1;
        res._cell = _curPlace._cell;
    }

    return res;
}

int FindAns () {
    int res = 0;
    Place fuPlace; // future Place

    //cout << _lineM << endl;

    _myHash[_curPlace._line][_curPlace._cell]++;

    for (int i = 0; i < _optNum; i++) {
        fuPlace._line = Move()._line;
        fuPlace._cell = Move()._cell;
        if (fuPlace._line > 0 && fuPlace._line < _lineM + 1 && fuPlace._cell > 0 && fuPlace._cell < _cellM + 1 && _myMap[fuPlace._line][fuPlace._cell] != -1) {
            _curPlace._line = fuPlace._line;
            _curPlace._cell = fuPlace._cell;
        }
        else {
            _curDir = (_curDir + 1) % 4;
        }
        //cout << fuPlace._line << "," << fuPlace._cell << "," << _curDir << endl;
        fuPlace._line = 0;
        fuPlace._cell = 0;
        _myHash[_curPlace._line][_curPlace._cell]++;
    }

    for (int i = 1; i < _lineM + 1; i++) {
        for (int m = 1; m < _cellM + 1; m++) {
            if (_myHash[i][m] > 0) {
                res++;
            }
        }
    }

    return res;
}

void Core () {
    int maxi = 0;
    int res = 0;
    char curChar = '!';

    ifstream inFile("explore.in");
    ofstream outFile("explore.out");

    inFile >> maxi;

    for (int i = 0; i < maxi; i++) {
        inFile >> _lineM >> _cellM >> _optNum;
        inFile >> _curPlace._line >> _curPlace._cell >> _curDir;

        for (int i = 1; i < _lineM + 1; i++) {
            for (int m = 1; m < _cellM + 1; m++) {
                inFile >> curChar;
                if (curChar == 'x') {
                    _myMap[i][m] = -1;
                }
            }
        }
        //cout << _lineM << endl;
        res = FindAns();
        outFile << res << endl;
       // cout << endl;

        FillHash();
    }

    outFile.close();
    inFile.close();
}

int main () {

    Core();

    return 0;
}
