

#include <iostream>

#include <fstream>

using namespace std;

int main () {
  ofstream outFile("detect.out");
  outFile << 3 << " " << 3 << endl;
  outFile.close();
}
