

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

struct Car {
  int d;
  int v0;
  int a;
};

struct Res {
  string res;
  int cc;
};

int n = 0;
int m = 0;
int l = 0;
int v = 0;
int T = 0;
int maxD = 0;
string cur = "";
int total = 0;
int ans = 0;
int cnt = 0;
vector<Car> carList;
vector<int> detectList;
vector<Res> resList;

void GenDetect (int index, double starti, double endi) {
  cnt = 0;
  string curStr = cur;
  for (int i = 0; i < detectList.size(); i++) {
    if (detectList[i] >= starti && detectList[i] <= endi) {
      curStr[i] = '1';
      cnt++;
    }
  }
  if (curStr != cur) {
    total++;
    //  cout << curStr << "," << cnt << endl;
    resList.push_back({curStr, cnt});
  }
}

void GenDetectL (int index, double starti, double endi) {
  string curStr = cur;
  cnt = 0;
  for (int i = 0; i < detectList.size(); i++) {
    if (detectList[i] > starti && detectList[i] <= endi) {
      curStr[i] = '1';
      cnt++;
    }
  }
  if (curStr != cur) {
    total++;
    //cout << curStr << "," << cnt << endl;
    resList.push_back({curStr, cnt});
  }
}

void GenDetectR (int index, double starti, double endi) {
  string curStr = cur;
  cnt = 0;
  for (int i = 0; i < detectList.size(); i++) {
    if (detectList[i] >= starti && detectList[i] < endi) {
      curStr[i] = '1';
      cnt++;
    }
  }
  if (curStr != cur) {
    total++;
    //cout << curStr << "," << cnt << endl;
    resList.push_back({curStr, cnt});
  }
}

void FindOver () {
  Car solo;
  for (int i = 0; i < n; i++) {
    solo = carList[i];
    if (solo.a == 0) {
      if (solo.v0 > v) {
	  GenDetect(i, solo.d, l);
      }
      else {
	continue;
      }
    }

    if (solo.a > 0) {
      if (solo.v0 > v) {
	GenDetect(i, solo.d, l);
      }
      else {
	double x = double(v*v-solo.v0*solo.v0) / double(2 * solo.a);
	GenDetectL(i, double(solo.d+x), l);
      }
    }

    if (solo.a < 0) {
      if (solo.v0 <= v) {
	continue;
      }
      double x = double(v*v-solo.v0*solo.v0) / double(2 * solo.a);
      GenDetectR(i, solo.d, double(solo.d+x));
    }
  }
}

void CalcRemove () {
  bool flag = false;
  //every cell
  for (int i = 0; i < m; i++) {
    //every line
    for (int j = 0; j < resList.size(); j++) {
      if (resList[j].cc == 1 && resList[j].res[i] == '1') {
	//cout << "P->" << j << endl;
	flag = true;
      }
    }
    if (flag) {
      //cout << i << endl;
      flag = false;
      continue;
    }

    for (int j = 0; j < resList.size(); j++) {
      if (resList[j].res[i] == '1') {
	resList[j].cc--;
      }
      resList[j].res[i] = '0';
    }
    ans++;
  }
}

void ParseIn () {
  Car solo;
  bool allZero = true;
  bool neg = true;
  bool pos = true;
  
  ifstream inFile("detect.in");
  ofstream outFile("detect.out");

  inFile >> T;

  for (int i = 0; i < T; i++) {
    inFile >> n >> m >> l >> v;

    for (int j = 0; j < m; j++) {
      cur += '0';
    }
    
    for (int j = 0; j < n; j++) {
      inFile >> solo.d >> solo.v0 >> solo.a;

      if (solo.a != 0) {
	allZero = false;
      }
      if (solo.a >= 0) {
	neg = false;
      }
      if (solo.a <= 0) {
	pos = false;
      }
      maxD = max(maxD, solo.d);
      carList.push_back(solo);
    }

    for (int j = 0; j < m; j++) {
      inFile >> solo.a;
      detectList.push_back(solo.a);
    }
    
    FindOver();
    outFile << total << " ";
    if (m <= 20) {
      CalcRemove();
      outFile << ans << endl;
    }
    if (allZero) {
      if (total > 0) {
	outFile << m - 1 << endl;
      }
      else {
	outFile << m << endl;
      }
    }
    else {
      if (m > 20) {
	CalcRemove();
	outFile << ans << endl;
      }
    }
    
    detectList.clear();
    carList.clear();
    resList.clear();
    total = 0;
    cur = "";
    ans = 0;
  }
  
  inFile.close();
  outFile.close();
}

int main () {

  ParseIn();
  
  return 0;
}
