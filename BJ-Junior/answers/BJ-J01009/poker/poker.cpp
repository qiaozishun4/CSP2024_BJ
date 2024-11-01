#include<bits/stdc++.h>
using namespace std;
string sh;
set<string> T;
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> sh;
        T.insert(sh);
    }
    cout << 52 - T.size();
    return 0;
}
