#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%7==0){
            while(n){
                n-=7;
                cout << 8;
            }
        }
        else if(n%7==1){
            if(n==1){
                cout << -1 << endl;
                continue;
            }
            n-=8;
            cout << 10;
            while(n){
                n-=7;
                cout << 8;
            }
        }
        else if(n%7==2){
            n-=2;
            cout << 1;
            while(n){
                n-=7;
                cout << 8;
            }
        }
        else if(n%7==3){
            if(n==3){
                cout << 7 << endl;
                continue;
            }
            if(n==10){
                cout << 22 << endl;
                continue;
            }
            n-=17;
            cout << 200;
            while(n){
                n-=7;
                cout << 8;
            }
        }
        else if(n%7==4){
            if(n==4){
                cout << 4 << endl;
                continue;
            }
            n-=11;
            cout << 20;
            while(n){
                n-=7;
                cout << 8;
            }
        }
        else if(n%7==5){
            if(n==3){
                cout << 7 << endl;
                continue;
            }
            n-=5;
            cout << 2;
            while(n){
                n-=7;
                cout << 8;
            }
        }
        else if(n%7==6){
            n-=6;
            cout << 6;
            while(n){
                n-=7;
                cout << 8;
            }
        }
        cout << endl;
    }
    return 0;
}
/*

a[] 0 1 2 3 4 5 6 7 8 9
val 6 2 5 5 4 5 6 4 7 6
          X   X   X   X
*/
