#include <bits/stdc++.h>
using namespace std;
int t;
int l[14] = {0,-1,1,7,4,2,6,8,10,18,22,20,28,68};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if (n >= 1 && n <= 13){
            cout <<l[n] << endl;
            continue;
        }
        if (n % 7 == 0){
            for (int i=0;i<n/7;i++){
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if (n % 7 == 1){
            cout << 10;
            for (int i=0;i<(n-1)/7-1;i++){
                cout <<8;
            }
            cout <<endl;
            continue;
        }
        if (n % 7 == 2){
            cout << 1;
            for (int i=0;i<(n-2)/7;i++){
                cout <<8;
            }
            cout <<endl;
            continue;
        }
        if (n % 7 == 3){
            cout <<200;
            for (int i=0;i<(n-3)/7-2;i++){
                cout <<8;
            }
            cout << endl;
            continue;
        }
        if (n % 7 == 4){
            cout <<20;
            for (int i=0;i<(n-4)/7-1;i++){
                cout <<8;
            }
            cout <<endl;
            continue;
        }
        if (n % 7 == 5){
            cout <<2;
            for (int i=0;i<(n-5)/7;i++){
                cout <<8;
            }
            cout << endl;
            continue;
        }
        if (n % 7 == 6){
            cout <<6;
            for (int i=0;i<(n-6)/7;i++){
                cout <<8;
            }
            cout << endl;
            continue;
        }
    }
    return 0;
}
