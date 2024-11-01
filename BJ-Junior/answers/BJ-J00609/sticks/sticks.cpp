#include <iostream>
#include <string>
using namespace std;
int f[] = {-1,-1,1,7,4,2,6,8,10,18,22,20};
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T; cin >>T;
    while (T--){
        int n; cin >> n;
        if (n <= 11) cout << f[n] << endl;
        else{
            if ((n-11)%7 == 0){
                cout << f[11];
                for (int i = 1; i <= (n-11)/7; i++) cout << 8;
                cout << endl;
            }
            else{
                cout << f[(n-11)%7+4];
                for (int i = 1; i <= (n-11)/7+1; i++) cout << 8;
                cout << endl;
            }
        }
    }
return 0;}
