

#include <iostream>
#include <fstream>

using namespace std;

struct DpStr {
    string _real;
    string _fake;
};

int _maxi = 0;
int _maxNum = 0;
int _myArray[59];
int _myHash[19];
string _dp[100009];

void ParseIn () {
    int curInt = 0;

    ifstream inFile("sticks.in");

    inFile >> _maxi;

    for (int i = 0; i < _maxi; i++) {
        inFile >> curInt;
        _maxNum = max(curInt, _maxNum);
        _myArray[i] = curInt;
    }

    inFile.close();
}

string minStr (string one, string two) {
    if (one == "") {
        return two;
    }
    if (two == "") {
        return one;
    }

    if (one.length() != two.length()) {
        if (one.length() < two.length()) {
            return one;
        }
        return two;
    }
    if (one < two) {
        return one;
    }
    return two;
}

void Core () {
    string curStr = "ERROR";
    char curChar = '!';

    _myHash[0] = 6;
    _myHash[1] = 2;
    _myHash[2] = 5;
    _myHash[3] = 5;
    _myHash[4] = 4;
    _myHash[5] = 5;
    _myHash[6] = 6;
    _myHash[7] = 3;
    _myHash[8] = 7;
    _myHash[9] = 6;

    _dp[1] = "-1";
    _dp[2] = "1";
    _dp[3] = "7";
    _dp[4] = "4";
    _dp[5] = "2";
    _dp[6] = "6";
    _dp[7] = "8";
    _dp[8] = "10";
    _dp[9] = "18";
    _dp[10] = "22";
    _dp[11] = "20";
    _dp[12] = "28";
    _dp[13] = "68";
    _dp[14] = "88";

    /*
    for (int i = 8; i < _maxNum + 1; i++) {
        _dp[i]._real = "";
        _dp[i]._fake = "";
        for (int m = 1; m < 10; m++) {
            if (i - _myHash[m] > 1) {
                curStr = _dp[i - _myHash[m]]._fake;
                curChar = m + '0';
                curStr = curChar + curStr;
                _dp[i]._real = minStr(curStr, _dp[i]._real);
          //      cout << curStr << endl;
            }
        }
        for (int m = 0; m < 10; m++) {
            if (i - _myHash[m] > 1) {
                curStr = _dp[i - _myHash[m]]._fake;
                curChar = m + '0';
                curStr = curChar + curStr;
                _dp[i]._fake = minStr(curStr, _dp[i]._fake);
            }
        }
        cout << i << "->" << _dp[i]._real << endl;
      //  cout << "," << _dp[i]._fake << endl;
    }
    */

    for (int i = 15; i < _maxNum + 1; i++) {
        if (i == 17) {
            _dp[i] = "200";
            continue;
        }
        _dp[i] = _dp[i - 7] + '8';
    }
}

void WriteOut () {
    ofstream outFile("sticks.out");

    for (int i = 0; i < _maxi; i++) {
        outFile << _dp[_myArray[i]] << endl;
    }

    outFile.close();
}

int main () {

    ParseIn();
    Core();
    WriteOut();

    return 0;
}
