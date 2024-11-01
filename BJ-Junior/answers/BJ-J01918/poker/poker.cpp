#include <iostream>
#include <set>
using namespace std;
int n;
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    set<string> pokers;
    string s;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s, pokers.insert(s);
    cout << 52 - pokers.size() << endl;
    return 0;
}
