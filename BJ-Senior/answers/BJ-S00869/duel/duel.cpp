

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int _numN = 0;
vector<int> _numList;

priority_queue<int> _numQueue;

int _res = 0;

bool Compare (int numOne, int numTwo) {
    return numOne > numTwo;
}

void ParseIn () {
    int curInt = 0;

    ifstream inFile("duel.in");

    inFile >> _numN;
    for (int i = 0; i < _numN; i++) {
        inFile >> curInt;
        _numList.push_back(curInt);
    }

    inFile.close();
}

void Core () {
    sort(_numList.begin(), _numList.end(), Compare);

    _res = _numN;

    for (auto solo : _numList) {
        // cout << solo << "," << _numQueue.size() << "->";
        if (!_numQueue.empty() && _numQueue.top() > solo) {
            _numQueue.pop();
            _res--;
            // cout << _numQueue.top() << "," << solo;
        }
        _numQueue.push(solo);
        // cout << endl;
    }
}

void CWriteOut () {
    cout << _res << endl;
}

void WriteOut () {
    ofstream outFile("duel.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn();
    Core();
    // CWriteOut();
    WriteOut();

    return 0;
}