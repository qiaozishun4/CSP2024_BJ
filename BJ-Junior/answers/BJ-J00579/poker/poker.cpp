#include <bits/stdc++.h>
using namespace std;
int n;
string s;
map<string, bool> mp;
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    int num = 0;
    for(int i = 1;i <= n;i++) {
        cin >> s;
        if(mp[s] == 1)
            continue;
        mp[s] = true;
        num++;
    }
    cout << 52 - num << endl;
    return 0;
}
