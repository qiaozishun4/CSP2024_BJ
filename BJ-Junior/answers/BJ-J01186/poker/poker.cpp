#include <bits/stdc++.h>
using namespace std;
int n, need, now;
string s;
set<string> t;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s;
        t.insert(s);
    }
    need = 52;
    now = t.size();
    cout << need - now << "\n";
    return 0;
}