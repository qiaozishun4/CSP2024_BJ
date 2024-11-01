

#include <iostream>
#include <fstream>

using namespace std;

int _maxi = 0;
int _myHash[9][19];
int _res = 0;

void ReadPoker (char color, char num) {
    int index1 = 0;
    int index2 = 0;

    if (color == 'D') {
        index1 = 1;
    }
    if (color == 'C') {
        index1 = 2;
    }
    if (color == 'H') {
        index1 = 3;
    }
    if (color == 'S') {
        index1 = 4;
    }

    if (num > '0' && num < '9' + 1) {
        index2 = num - '0';
    }
    if (num == 'T') {
        index2 = 10;
    }
    if (num == 'J') {
        index2 = 11;
    }
    if (num == 'Q') {
        index2 = 12;
    }
    if (num == 'K') {
        index2 = 13;
    }
    if (num == 'A') {
        index2 = 1;
    }

    _myHash[index1][index2]++;
}

void ParseIn () {
    char color = '!';
    char num = '!';

    ifstream inFile("poker.in");

    inFile >> _maxi;

    for (int i = 0; i < _maxi; i++) {
        inFile >> color >> num;
        ReadPoker(color, num);
    }

    inFile.close();
}

void Core () {
    for (int i = 1; i < 5; i++) {
        for (int m = 1; m < 14; m++) {
            if (_myHash[i][m] == 0) {
                _res++;
            }
        }
    }
}

void WriteOut () {
    ofstream outFile("poker.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {

    ParseIn();
    Core();
    WriteOut();

    return 0;
}
