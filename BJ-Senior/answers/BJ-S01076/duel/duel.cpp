

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

int _maxi = 0;
priority_queue<int, vector<int>, greater<int> > _myQueue1; // have not gongJi
priority_queue<int, vector<int>, greater<int> > _myQueue2; // already gongJi

void ParseIn () {
    int curInt = 0;

    ifstream inFile("duel.in");

    inFile >> _maxi;

    for (int i = 0; i < _maxi; i++) {
        inFile >> curInt;
        _myQueue1.push(curInt);
    }

    inFile.close();
}

void Core () {
    int curInt = 0;

    while (!_myQueue1.empty()) {
        if (_myQueue2.empty()) {
            curInt = _myQueue1.top();
            _myQueue2.push(curInt);
            _myQueue1.pop();
            continue;
        }
        if (_myQueue1.top() > _myQueue2.top()) {
            _maxi--;
            curInt = _myQueue1.top();
            _myQueue1.pop();
            _myQueue2.pop();
            _myQueue2.push(curInt);
            continue;
        }
        curInt = _myQueue1.top();
        _myQueue2.push(curInt);
        _myQueue1.pop();
    }
}

void WriteOut () {
    ofstream outFile("duel.out");

    outFile << _maxi << endl;

    outFile.close();
}

int main () {

    ParseIn();
    Core();
    WriteOut();

    return 0;
}
