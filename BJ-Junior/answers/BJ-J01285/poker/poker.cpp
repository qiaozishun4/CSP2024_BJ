#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, cnt = 0;
    cin >> t;
    set<string> s;
    while(t--){
        string x;
        cin >> x;
        s.insert(x);
    }
    for(auto it = s.begin(); it != s.end(); it++){
        cnt++;
    }
    cout << 52 - cnt;
    return 0;
}
