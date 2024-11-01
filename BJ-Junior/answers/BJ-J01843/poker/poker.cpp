#include<bits/stdc++.h>
using namespace std;
int n;
set<string> ji;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        string n;
        cin >> n;
        ji.insert(n);
    }
    cout << 52 - ji.size();
    return 0;
}
/*
3 3
1 2 1
1 3 1
2 3 2

*/
