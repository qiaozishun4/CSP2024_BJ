

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Car {
    int _dis; // distance when go on road;
    int _speed;// speed at first
    int _addSp; // add speed
    int _left;
    int _right;
};

int _maxiCar = 0; // maxi Car
int _maxiDe = 0; // maxi Detectors
int _len = 0;
int _limit = 0;// limit speed
Car _carArray[100009];
int _deArray[100009];
int _minLeft = 0x7fffffff;

void FindLR () {
    int solo = 0;
  //  cout << 1 << endl;

    for (int i = 0; i < _maxiCar; i++) {
       //     cout << i << endl;

        if (_carArray[i]._speed > _limit && _carArray[i]._addSp >= 0) {
            _carArray[i]._left = _carArray[i]._dis;
            _carArray[i]._right = _len;
            continue;
        }
        if (_carArray[i]._addSp <= 0 && _carArray[i]._speed <= _limit) {
            _carArray[i]._left = -1;
            _carArray[i]._right = -1;
            continue;
        }
        if (_carArray[i]._addSp > 0) {
               // cout << 1 << endl;
            solo = _limit * _limit - _carArray[i]._speed * _carArray[i]._speed;
            if (solo % (2 * _carArray[i]._addSp) == 0) {
                _carArray[i]._left = _carArray[i]._dis + min(solo / (2 * _carArray[i]._addSp) + 1, _len);
                _carArray[i]._right = _len;
            }
            else {
                _carArray[i]._left = _carArray[i]._dis + min(solo / (2 * _carArray[i]._addSp) + 1, _len);
                _carArray[i]._right = _len;
            }
        }
        else {
       //     cout << 1 << endl;
            solo = (_limit * _limit - _carArray[i]._speed * _carArray[i]._speed) * -1;
            if (solo % (-2 * _carArray[i]._addSp) == 0) {
                _carArray[i]._left = _carArray[i]._dis;
                _carArray[i]._right = _carArray[i]._dis + min(solo / (-2 * _carArray[i]._addSp) - 1, _len);
            }
            else {
                _carArray[i]._left = _carArray[i]._dis;
                _carArray[i]._right = _carArray[i]._dis + min(solo / (-2 * _carArray[i]._addSp), _len);
            }
        }

    }



}

bool CompareCar (Car one, Car two) {
    return one._left < two._left;
}

bool CompareInt (int one, int two) {
    return one > two;
}

void Core () {
    int maxi = 0;
    Car curCar;

    ifstream inFile("detect.in");
    ofstream outFile("detect.out");

    inFile >> maxi;

    for (int i = 0; i < maxi; i++) {
        bool spA = true;
        bool spB = true;
        inFile >> _maxiCar >> _maxiDe >> _len >> _limit;
        for (int m = 0; m < _maxiCar; m++) {
            inFile >> curCar._dis >> curCar._speed >> curCar._addSp;
            if (curCar._addSp != 0) {
                spA = false;
            }
            if (curCar._addSp <= 0) {
                spB = false;
            }
            _carArray[m] = curCar;
        }
        FindLR();
        for (int m = 0; m < _maxiDe; m++) {
            inFile >> _deArray[m];
        }
        if (spA == true || spB == true) {
            bool _out = false;

            sort(_carArray, _carArray + _maxiCar, CompareCar);
            sort(_deArray, _deArray + _maxiDe, CompareInt);
        //    cout << _carArray[0]._left << "," << _deArray[0] << endl;
            for (int m = 0; m < _maxiCar; m++) {
                if (_carArray[m]._left == -1) {
                    
                    continue;
                }
                if (_deArray[0] >= _carArray[m]._left) {
                    //cout << 1 << endl;
                    outFile << _maxiCar - m << " " << _maxiDe - 1 << endl;
                    _out = true;
                    break;
                }
            }
            if (!_out) {
               outFile << 0 << " " << _maxiDe << endl;
            }
            //cout << 1 << endl;
        }

    }

    outFile.close();
    inFile.close();
}

int main () {

    Core();

    return 0;
}
