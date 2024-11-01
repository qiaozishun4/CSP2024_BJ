

#include <iostream>
#include <algorithm>

#include <fstream>

using namespace std;

char _hs[59], _ds[59];
string _strli[59];
int _cc = 0;
int n;


void ParseIn () {
    ifstream inFile("poker.in");
    inFile >> n;
    for (int i = 1; i <= n; i++) {
        inFile >> _hs[i] >> _ds[i];
        string solo;
        solo += _hs[i];
        solo += _ds[i];
        _strli[i] = solo;
    }
    inFile.close();
}

void Core () {
    _strli[0] = "hahahaha";
    sort(_strli + 1, _strli + n + 1);
    for (int i = 1; i <= n; i++) {
        if (_strli[i] != _strli[i - 1]) {
            _cc++;
            
        }
        
    }
    ofstream outFile("poker.out");
    outFile << 52 - _cc << endl;
    outFile.close();
}

int main () {
    ParseIn();
    Core();
    return 0;
}