#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, cnt;
map<string, int> mp;

int main() {
    freopen("poker.in", "r", stddin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        mp[s]++;
        if (mp[s] == 1)
            cnt++;
    }
    cout << 52-cnt << endl;
    return 0;
}
