#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 1){
            cout << -1;
        }
        if(n % 7 == 0){
            for(int i = 0; i < n / 7; i++){
                cout << 8;
            }
            return 0;
        }
        int x = n / 7 - 1, y = n % 7 + 7;
        for(int i = 0; i < x; i++){
            cout << 8;
        }
        if(y == 8){
            cout << 16;
        }else if(y == 9){
            cout << 18;
        }else if(y == 10){
            cout << 23;
        }else if(y == 11){
            cout << 47;
        }else if(y == 12){
            cout << 28;
        }else if(y == 13){
            cout << 68;
        }
        cout << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
