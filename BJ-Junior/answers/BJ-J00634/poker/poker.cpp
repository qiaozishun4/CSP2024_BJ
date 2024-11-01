#include<bits/stdc++.h>
using namespace std;

map<string, int> mp;
int cnt = 52, n;
string x;

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >>n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        mp[x]++;
        if(mp[x] == 1) cnt--;
    }
    cout << cnt << endl;
    return 0;
}
