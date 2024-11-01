

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int T = 0;
int ans = 0;
int res = 0;
int n = 0;
vector<int> myList;
int bitList[10009];

int Power (int cc) {
  int p = 1;
  for (int i = 0; i < cc; i++) {
    p *= 2;
  }
  return p;
}

int Find (int index) {
  for (int i = index - 1; i > -1; i--) {
    if (bitList[index] == bitList[i]) {
      return i;
    }
  }
  return -1;
}

void Calc () {
  int cc = 0;
  for (int i = 1; i < Power(n); i++) {
    int num = i;
    cc = 0;
    while (num > 0) {
      bitList[cc] = num % 2;
      num /= 2;
      cc++;
    }

    for (int j = 0; j < myList.size(); j++) {
      int solo = Find(j);
      if (solo == -1) {
	continue;
      }
      if (myList[j] == myList[solo]) {
	res += myList[j];
      }
    }
    ans = max(ans, res);
    res = 0;
    memset(bitList, 0, sizeof(bitList));
  }
  
}

void ParseIn () {
  int cur = 0;

  ifstream inFile("color.in");
  ofstream outFile("color.out");
  
  inFile >> T;
  for (int i = 0; i < T; i++) {
    inFile >> n;
    for (int j = 0; j < n; j++) {
      inFile >> cur;
      myList.push_back(cur);
    }

    Calc();
    outFile << ans << endl;

    ans = 0;
    myList.clear();
  }
  
  inFile.close();
  outFile.close();
}

int main () {

  ParseIn();

  return 0;
}
