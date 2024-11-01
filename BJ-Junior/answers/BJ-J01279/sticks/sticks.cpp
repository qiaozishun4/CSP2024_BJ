#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,t;
    cin >> t;
    for(int i = 0;i < t;i++){
        cin >> n;
        if(n < 2){
            cout << -1;
            continue;
        }
        if(n % 7 == 0){
            for(int i = 0;i < n/7;i++){
                cout << 8;
            }
            cout << endl;
        }else if(n % 7 == 1){
            cout << 10;
            for(int i = 0;i < (n-8)/7;i++){
                cout << 8;
            }
            cout << endl;
        }else if(n % 7 == 5){
            cout << 2;
            for(int i = 0;i < n/7;i++){
                cout << 8;
            }
            cout << endl;
        }else if(n % 7 == 6){
            cout << 80;
            for(int i = 0;i < (n-13)/7;i++){
                cout << 8;
            }
            cout << endl;
        }else if(n % 7 == 2){
            cout << 1;
            for(int i = 0;i < n/7;i++){
                cout << 8;
            }
            cout << endl;
        }else if(n % 7 == 3){
            cout << 22;
            for(int i = 0;i < (n-10)/7;i++){
                cout << 8;
            }
            cout << endl;
        }else if(n % 7 == 4){
            cout << 20;
            for(int i = 0;i < (n-11)/7;i++){
                cout << 8;
            }
            cout << endl;
        }
    }
    return 0;
}