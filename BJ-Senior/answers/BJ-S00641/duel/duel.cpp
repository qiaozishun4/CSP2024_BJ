//BJ-S00641 duel.cpp
//1234 AC
//Locked
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int b[100005];

int main() {

    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    int n, maxn = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        b[x]++;
    }
    for (int i = 1; i <= 100000; i++) maxn = max(maxn, b[i]);
    cout << maxn << endl;
    return 0;
}

