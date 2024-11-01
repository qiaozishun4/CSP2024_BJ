#include <bits/stdc++.h>
using namespace std;

set<string> s;
int n;

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        string p; cin >> p;
        s.insert(p);
    }
    cout << 52 - (int)s.size() << endl;
    return 0;
}
