

#include <iostream>
#include <fstream>

using namespace std;

int n = 0;
int cc = 0;
int a[100009];
int cnt[100009];
int maxi = 0;
int mini = 100005;

void ParseIn () {

  ifstream inFile("duel.in");

  inFile >> n;
  for (int i = 1; i < n + 1; i++) {
    inFile >> a[i];
    cnt[a[i]]++;
    maxi = max(a[i], maxi);
    mini = min(a[i], mini);
  }
  
  inFile.close();
}

void Core () {
  int sum = 0;
  for (int i = mini; i <= maxi; i++) {
    if (i == mini) {
      sum = cnt[i];
      continue;
    }
    cc += min(sum, cnt[i]);
    sum -= min(sum, cnt[i]);
    sum += cnt[i];
  }
}

void CWriteOut () {
  cout << n - cc << endl;
}

void WriteOut () {
  ofstream outFile("duel.out");

  outFile << n - cc << endl;

  outFile.close();
}

int main () {

  ParseIn();
  Core();
  WriteOut();

  return 0;
}
