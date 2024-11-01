#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> mp;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, ans = 0; cin >> n;
    for (int i = 1; i <= n; i++){
        string s; cin >> s;
        mp[s]++;
    }
    for (auto x:mp){
        ans++;
    }
    cout << 52-ans << endl;
return 0;}
