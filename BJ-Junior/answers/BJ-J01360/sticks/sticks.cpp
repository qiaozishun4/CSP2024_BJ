#include <bits/stdc++.h>
using namespace std;
const int N = 21;
int a[] = {-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,228,208,288,688};
void et(int n){
    for(int i = 1; i <= n/7; i++) cout << 8;
    cout << endl;
}
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        if(n<=20) {cout << a[n] << endl;continue;}
        if(n == 1){
            cout << -1 << endl;
            continue;
        }
        if(n == 3){
            cout << 7 << endl;
            continue;
        }
        if(n == 4){
            cout << 4 << endl;
            continue;
        }
        if(n % 7 == 0) {
            et(n);
            continue;
        }
        if(n % 7 == 1){
            cout << 10;
            et(n-8);
            continue;
        }
        if(n % 7 == 2){
            cout << 1;
            et(n-2);
            continue;
        }
        if(n % 7 == 3){
            cout << 22;
            et(n-10);
            continue;
        }
        if(n % 7 == 4){
            cout << 20;
            et(n-11);
            continue;
        }
        if(n % 7 == 5){
            cout << 2;
            et(n-5);
            continue;
        }
        if(n % 7 == 6){
            cout << 6;
            et(n-6);
            continue;
        }
    }
    return 0;
}
