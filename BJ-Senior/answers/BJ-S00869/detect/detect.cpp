

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXI = 1e5 + 9;

struct Car {
    int _numD;
    int _numV;
    int _numA;
};

struct Range {
    int _left;
    int _right;

    bool operator< (Range solo) const {
        if (_left == solo._left) {
            return _right < solo._right;
        }
        return _left < solo._left;
    }
};

int _dataN = 0;

int _carN = 0;
int _surN = 0;
int _lenN = 0;
int _limN = 0;

vector<Car> _carList;
vector<int> _surList;

vector<Range> _rangeList;

int _dpTab[MAXI];

vector<int> _resOneList;
vector<int> _resTwoList;

int GetIndexInSurList (int num) {
    int left = 0;
    int right = _surN - 1;
    int mid = 0;

    while (left < right) {
        mid = (left + right + 1) / 2;

        // cout << left << "," << right << endl;
        
        if (_surList[mid] > num) {
            right = mid - 1;
            continue;
        }
        left = mid;
    }

    if (_surList[left] < num) {
        left++;
    }

    return left;
}

bool FindSurInRange (int left, int right) {
    if (_surList[GetIndexInSurList(left)] > left - 1 && _surList[GetIndexInSurList(left)] < right + 1) {
        return true;
    }
    // cout << left << "," << right << "->" << _surList[GetIndexInSurList(left)] << endl;
    return false;
}

void GenRangeList () {
    Range solo;

    double border = 0.0;

    for (auto curCar : _carList) {
        if (curCar._numA == 0) {
            if (curCar._numV > _limN) {
                solo._left = curCar._numD;
                solo._right = _lenN;

                if (FindSurInRange(solo._left, solo._right)) {
                    _rangeList.push_back(solo);
                }
            }
            continue;
        }

        border = curCar._numD + (_limN * _limN - curCar._numV * curCar._numV) / 2.0 / curCar._numA;
        // cout << border << endl;

        if (curCar._numA > 0 && border <= _lenN) {
            if (border == (int) border) {
                border += 1;
            }
            solo._left = max(curCar._numD, (int) border);
            solo._right = _lenN;

            if (FindSurInRange(solo._left, solo._right)) {
                _rangeList.push_back(solo);
            }
            continue;
        }

        if (curCar._numA < 0 && border >= curCar._numD) {
            if (border == (int) border) {
                border -= 1;
            }
            solo._left = curCar._numD;
            solo._right = min(_lenN, (int) border);

            if (FindSurInRange(solo._left, solo._right)) {
                _rangeList.push_back(solo);
            }
            continue;
        }
    }
}

void DisplayRangeList () {
    for (auto solo : _rangeList) {
        cout << solo._left << "," << solo._right << endl;
    }
}

void DisplayDpTab () {
    for (int i = 0; i < _rangeList.size(); i++) {
        cout << _dpTab[i] << ",";
    }
    cout << endl;
}

void GenDpTab () {
    int temp = 0;
    int lastLeft = 0;
    int lastRight = 0;
    bool flag = false;
    bool selectedNew = false;

    for (int i = 0; i < _surN; i++) {
        flag = false;
        selectedNew = false;

        if (_surList[i] > lastLeft - 1 && _surList[i] < lastRight + 1) {
            for (int m = temp; m < _rangeList.size(); m++) {
                if (_surList[i] > _rangeList[m]._left - 1 && _surList[i] < _rangeList[m]._right + 1) {                    
                    lastLeft = max(lastLeft, _rangeList[m]._left);
                    lastRight = min(lastRight, _rangeList[m]._right);

                    _dpTab[m] = _dpTab[temp - 1];
                    continue;
                }

                temp = m;
                flag = true;
                break;
            }

            if (!flag) {
                temp = _rangeList.size();
            }

            // DisplayDpTab();
            // cout << "A->" << lastLeft << "," << lastRight << endl;
            continue;
        }

        for (int m = temp; m < _rangeList.size(); m++) {
            if (_surList[i] > _rangeList[m]._left - 1 && _surList[i] < _rangeList[m]._right + 1) {
                if (!selectedNew) {
                    selectedNew = true;
                    lastLeft = 0;
                    lastRight = _lenN;
                }

                if (temp - 1 < 0) {
                    _dpTab[m] = 1;
                    lastLeft = max(lastLeft, _rangeList[m]._left);
                    lastRight = min(lastRight, _rangeList[m]._right);
                    continue;
                }

                _dpTab[m] = _dpTab[temp - 1] + 1;
                lastLeft = max(lastLeft, _rangeList[m]._left);
                lastRight = min(lastRight, _rangeList[m]._right);
                continue;
            }

            temp = m;
            flag = true;
            break;
        }

        if (!flag) {
            temp = _rangeList.size();
        }

        // DisplayDpTab();
        // cout << lastLeft << "," << lastRight << endl;
    }
}

void Core () {
    Car curCar;
    int curInt;

    ifstream inFile("detect.in");

    inFile >> _dataN;
    for (int i = 0; i < _dataN; i++) {
        _carList.clear();
        _surList.clear();
        _rangeList.clear();
        memset(_dpTab, 0, sizeof(_dpTab));

        inFile >> _carN >> _surN >> _lenN >> _limN;

        for (int m = 0; m < _carN; m++) {
            inFile >> curCar._numD >> curCar._numV >> curCar._numA;
            _carList.push_back(curCar);
        }

        for (int m = 0; m < _surN; m++) {
            inFile >> curInt;
            _surList.push_back(curInt);
        }

        GenRangeList();
        sort(_rangeList.begin(), _rangeList.end());
        // DisplayRangeList();

        GenDpTab();
        // DisplayDpTab();

        _resOneList.push_back(_rangeList.size());
        _resTwoList.push_back(_surN - _dpTab[_rangeList.size() - 1]);
    }

    inFile.close();
}

void CWriteOut () {
    for (int i = 0; i < _dataN; i++) {
        cout << _resOneList[i] << " " << _resTwoList[i] << endl;
    }
}

void WriteOut () {
    ofstream outFile("detect.out");

    for (int i = 0; i < _dataN; i++) {
        outFile << _resOneList[i] << " " << _resTwoList[i] << endl;
    }

    outFile.close();
}

int main () {
    Core();
    // CWriteOut();
    WriteOut();

    return 0;
}