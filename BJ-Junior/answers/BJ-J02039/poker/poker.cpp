#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
set <string> se;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(ll i = 1; i <= n; i++){
        string s;
        cin >> s;
        se.insert(s);
    }
    cout << 52 - se.size();
    return 0;
}
