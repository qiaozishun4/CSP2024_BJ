#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        int a, b, c;
        cin >> a >> b >> c;
        int x = a + b + c;
        cout << x % 2 << endl;
    }
}