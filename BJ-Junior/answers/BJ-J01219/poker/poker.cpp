#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    unordered_set<string> s;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        s.insert(str);
    }
    cout << 52 - s.size();
    return 0;
}