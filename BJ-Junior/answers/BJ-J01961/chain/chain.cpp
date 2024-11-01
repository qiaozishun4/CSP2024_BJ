#include <iostream>
#include <fstream>

using namespace std;

int main () {
ofstream outFile("chain.out");
outFile >> 1;
outFile.close();
return 0;
}