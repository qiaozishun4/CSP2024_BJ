//BJ-J00771 sticks.cpp
//12 AC 3 MLE
//Writing
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int NUM[10] = {8, 16, 18, 22, 20, 28, 68};
const char NUMS[10] = {'0', '0', '1', '2', '4', '6', '7', '8'};
const int USES[10] = {0, 6, 2, 5, 4, 6, 3, 7};

int n;

string f[100005][10];

string Min(string x, string y) {
    if (x == "") return y;
    if (y == "") return x;
    if (x.size() != y.size()) return (x.size() < y.size() ? x : y);
    return (x < y ? x : y);
}

void Reset() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 7; j++) {
            f[i][j] = "";
        }
    }
    return;
}

void Write() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 7; j++) {
            for (int k = 1; k <= 7; k++) {
                if (i > USES[j] && f[i - USES[j]][k] == "") continue;
                if (i >= USES[j]) f[i][j] = Min(f[i][j], NUMS[j] + f[i - USES[j]][k]);
            }
            //printf("%2d,%2d=%s ", i, j, f[i][j].c_str());
        }
        //printf("\n");
    }
    return;
}

string Calc() {
    string minn = "";
    for (int i = 2; i <= 7; i++) minn = Min(minn, f[n][i]);
    if (minn == "") return "-1";
    return minn;
}

int main() {

    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    int TEST;
    cin >> TEST;
    while (TEST--) {
        cin >> n;
        if (n >= 1000) {
            cout << NUM[n % 7];
            if (n % 7 == 0) for (int i = 1; i < n / 7; i++) cout << '8';
            else for (int i = 1; i <= n / 7; i++) cout << '8';
            cout << endl;
            continue;
        }
        Reset();
        Write();
        cout << Calc() << endl;
    }
    return 0;
}

