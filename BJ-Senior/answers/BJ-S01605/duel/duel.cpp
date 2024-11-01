

#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int _hs[100009];
int _cc;
int n;
void ParseIn () {
    ifstream inFile("duel.in");
    inFile >> n;
    for (int i = 1; i <= n; i++) {
        int attacksolo;
        inFile >> attacksolo;
        _hs[attacksolo]++;

    }
    inFile.close();
}
void Core () {
    int before = 0;
    for (int i = 1; i <= 100000; i++) {
        if (_hs[i] != 0) {
            int solo = max(0, before - _hs[i]);
            _cc += (before - solo);
            _hs[i] += solo;
            before = _hs[i];

        }

    }
    ofstream outFile("duel.out");
    outFile << n - _cc << endl;
    outFile.close();
}

int main () {
    ParseIn();
    Core();
    return 0;
}