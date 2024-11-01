#include <iostream>
#include <fstream>
using namespace std;
int n,mx=0;
int a[100010];
int b[100010];
int c[100010];
int cc=0;
int main () {
  ifstream in("duel.in");
  ofstream out("duel.out");
  in >> n;
  for (int i = 1; i <= n; i++) {
    in >> a[i];
    b[a[i]]++;
    if (mx < a[i]) {
      mx=a[i];
    }
  }
  for (int i = 1; i <= mx; i++) {
    if (b[i]==0) {
      continue;
    }
    c[++cc]=b[i];
  }
  for (int i = 1; i < cc; i++) { 
    if (c[i]<=c[i+1]) {
      continue;
    }
    else {
      c[i+1]=c[i];
    }
  }
  out << c[cc] << endl;
  in.close();
  out.close();
  return 0;
}