#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while (t --){
        int n;
        cin >> n;
        if (n == 1){
            cout << -1 << endl;
            continue;
        }
        if (n == 3){
            cout << 7 << endl;
            continue;
        }
        if (n == 4){
            cout << 4 << endl;
            continue;
        }
        int p = n / 7;
        if (n % 7 == 1)
            cout << "16", p --;
        if (n % 7 == 2)
            cout << '1';
        if (n % 7 == 3)
            cout << "22", p --;
        if (n % 7 == 4)
            cout << "20", p --;
        if (n % 7 == 5)
            cout << '2';
        if (n % 7 == 6)
            cout << '6';
        for (int i = 1; i <= p; i ++)
            cout << '8';
        cout << endl;
    }
    return 0;
}