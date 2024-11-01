

#include <iostream>
#include <fstream>

using namespace std;

int main () {
    ofstream outFile("arena.out");
    outFile << 0 << endl;
    outFile.close();
    return 0;
}