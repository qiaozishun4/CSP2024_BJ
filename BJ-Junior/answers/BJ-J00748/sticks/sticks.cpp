#include<iostream>
using namespace std;

int t, n, c, c2;
string m;
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> n;
        if (n == 1){
            cout << -1;
        } if (n == 2){
            cout << 1;
        } if (n == 3){
            cout << 7;
        } if (n == 4){
            cout << 4;
        } if (n == 5){
            cout << 2;
        } if (n == 6){
            cout << 6;
        } if (n == 7){
            cout << 8;
        } if (n >= 8){
            c = n % 7;
            c2 = (n - 1) / 7 + 1;
            if (c == 0){
                for (int i = 1; i <= c2; ++i){
                    cout << 8;
                }
            }
            if (c == 1){
                cout << 10;
                for (int i = 3; i <= c2; ++i){
                    cout << 8;
                }
            }
            if (c == 2){
                cout << 1;
                for (int i = 2; i <= c2; ++i){
                    cout << 8;
                }
            }if (c == 3){
                if (n == 10){
                    cout << 22 << endl;
                    continue;
                } else {
                    cout << 200;
                    for (int i = 4; i <= c2; ++i){
                        cout << 8;
                    }
                }
            }
            if (c == 4){
                cout << 20;
                for (int i = 3; i <= c2; ++i){
                    cout << 8;
                }
            }
            if (c == 5){
                cout << 2;
                for (int i = 2; i <= c2; ++i){
                    cout << 8;
                }
            }
            if (c == 6){
                cout << 6;
                for (int i = 2; i <= c2; ++i){
                    cout << 8;
                }
            }
        }
        cout << endl;
    }
}
