#include<bits/stdc++.h>
using namespace std;
void out_(int num,int t){
    while(t--){
        printf("%d",num);
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n <= 1) cout << -1 << endl;
        else if(n % 7 == 0){
            n /= 7;
            out_(8,n);
            cout << endl;
        }
        else if(n % 7 == 1){
            n--;
            n /= 7;
            cout << 10;
            out_(8,n - 1);
            cout << endl;
        }
        else if(n % 7 == 2){
            n -= 2;
            n /= 7;
            cout << 1;
            out_(8,n);
            cout << endl;
        }
        else if(n % 7 == 3){
            if(n == 3){
                cout << 7 << endl;
                continue;
            }
            cout << 22;
            n -= 3;
            n /= 7;
            out_(8,n - 1);
            cout << endl;
        }
        else if(n % 7 == 4){
            if(n == 4){
                cout << 4 << endl;
                continue;
            }
            cout << 20;
            n -= 4;
            n /= 7;
            out_(8,n - 1);
            cout << endl;
        }
        else if(n % 7 == 5){
            n -= 5;
            n /= 7;
            cout << 2;
            out_(8,n);
            cout << endl;
        }
        else if(n % 7 == 6){
            n -= 6;
            n /= 7;
            cout << 6;
            out_(8,n);
            cout << endl;
        }
    }
    return 0;
}
