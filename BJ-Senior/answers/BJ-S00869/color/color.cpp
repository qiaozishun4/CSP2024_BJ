

#include <iostream>
#include <fstream>
#include <vector>

#define int long long

using namespace std;

const int MAXI = 2e5 + 9;

int _dataN = 0;

int _numN = 0;
vector<int> _numList;

bool _numHash[MAXI];

int _res = 0;
vector<int> _resList;

int ComputeRes () {
    int lastFalse = -1;
    int lastTrue = -1;

    int curRes = 0;

    for (int i = 0; i < _numN; i++) {
        if (_numHash[i]) {
            if (_numList[i] == lastTrue) {
                curRes += _numList[i];
            }
            lastTrue = _numList[i];
            continue;
        }

        if (_numList[i] == lastFalse) {
            curRes += _numList[i];
        }
        lastFalse = _numList[i];
        continue;
    }

    return curRes;
}

void Search (int index) {
    if (index == _numN) {
        _res = max(_res, ComputeRes());
        return;
    }

    _numHash[index] = true;
    Search(index + 1);

    _numHash[index] = false;
    Search(index + 1);
}

void Core () {
    int curInt = 0;

    ifstream inFile("color.in");

    inFile >> _dataN;
    for (int i = 0; i < _dataN; i++) {
        _numList.clear();

        inFile >> _numN;
        for (int m = 0; m < _numN; m++) {
            inFile >> curInt;
            _numList.push_back(curInt);
        }

        _res = 0;
        Search(0);
        _resList.push_back(_res);
    }

    inFile.close();
}

void CWriteOut () {
    for (auto solo : _resList) {
        cout << solo << endl;
    }
}

void WriteOut () {
    ofstream outFile("color.out");

    for (auto solo : _resList) {
        outFile << solo << endl;
    }

    outFile.close();
}

signed main () {
    Core();
    // CWriteOut();
    WriteOut();

    return 0;
}