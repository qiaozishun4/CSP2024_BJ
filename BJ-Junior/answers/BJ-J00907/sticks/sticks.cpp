#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,t;
    cin >> t;
    for(int i = 0;i < t;i++){
        cin >> n;
        if(n % 7 == 0) {
           for(int j = 0;j < n / 7;j++) cout << "8" ;
           cout << "\n";
        }
        if((n - 1) % 7 == 0) {
           cout << "10";
           for(int j = 0;j < n / 7 - 1;j++) cout << "8";
           cout << "\n";
        }
    }
    return 0;
}