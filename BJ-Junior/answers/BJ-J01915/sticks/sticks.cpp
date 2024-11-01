#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
signed main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        if(n == 1){
            cout << -1 << endl;
            continue;
        }
        if(n == 2){
            cout << 1 << endl;
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
        if(n == 5){
            cout << 2 << endl;
            continue;
        }
        if(n == 6){
            cout << 0 << endl;
            continue;
        }
        if(n % 7 == 0){
            for(int i = 1;i <= n / 7;i++) cout << 8;
            cout << endl;
        }
        else if(n % 7 == 1){
            cout << 10;
            for(int i = 1;i <= n / 2 - 1;i++) cout << 8;
            cout << endl;
        }
        else if(n % 7 == 2){
            cout << 1;
            for(int i = 1;i <= n / 7;i++) cout << 8;
            cout << endl;
        }
        else if(n % 7 == 3){
            if(n == 10) cout << 22 << endl;
            else{
                cout << 200;
                for(int i = 1;i <= n / 7-2;i++) cout << 8;
                cout << endl;
            }
        }
        else if(n % 7 == 4){
            cout << 20;
            for(int i = 1;i <= n / 7-1;i++) cout << 8;
            cout << endl;
        }
        else if(n % 7 == 5){
            cout << 2;
            for(int i = 1;i <= n / 7;i++) cout << 8;
            cout << endl;
        }
        else{
            cout << 6;
            for(int i = 1;i <= n / 7;i++) cout << 8;
            cout << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
