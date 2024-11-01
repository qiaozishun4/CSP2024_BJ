#include<bits/stdc++.h>
using namespace std;

int T;
int n;
int sticks[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    cin >> T;

    while(T--){
        cin >> n;

        if(n == 1 || n == 0){
            cout << -1 << endl;
            continue;
        }
        else if(1 < n && n < 7){
            for(int i=0; i<=9; i++){
                if(n == sticks[i] && i != 0){
                    cout << i << endl;
                    break;
                }
            }
        }
        else if(n%7 == 0){
            for(int i=1; i<=n/7; i++){
                cout << 8;
            }
            cout << endl;
        }
        else if(n%7 == 1){
            n-= 7;
            cout <<10;
            for(int i=1; i<=n/7; i++){
                cout << 8;
            }
            cout << endl;
        }
        else if(n%7 == 2){
            n-= 7;
            cout <<18;
            for(int i=1; i<=n/7; i++){
                cout << 8;
            }
            cout << endl;
        }
        else if(n%7 == 3){
            n-= 7;
            cout <<22;
            for(int i=1; i<=n/7; i++){
                cout << 8;
            }
            cout << endl;
        }
        else if(n%7 == 4){
            n-= 7;
            cout <<20;
            for(int i=1; i<=n/7; i++){
                cout << 8;
            }
            cout << endl;
        }
        else if(n%7 == 5){
            n-= 7;
            cout <<28;
            for(int i=1; i<=n/7; i++){
                cout << 8;
            }
            cout << endl;
        }
        else if(n%7 == 6){
            n-= 7;
            cout <<68;
            for(int i=1; i<=n/7; i++){
                cout << 8;
            }
            cout << endl;
        }
    }
    return 0;
}
