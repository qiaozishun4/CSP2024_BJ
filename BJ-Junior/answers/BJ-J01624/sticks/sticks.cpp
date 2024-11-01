#include<bits/stdc++.h>
using namespace std;
int n, t;
int main (){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >>t;
    while(t--){
        cin >> n;
        if(n%7 == 0){
            int k = n/7;
            for(int i = 0;i<k;i++){
                cout << "8";
            }
            cout << endl;
        }
        if(n<7){
            if(n == 2) cout << 1<<endl;
            if(n == 3) cout << 7 <<endl;
            if(n == 4) cout << 4 <<endl;
            if(n == 5) cout << 2 <<endl;
            if(n == 6) cout << 6 <<endl;
            if(n == 7) cout << 8 <<endl;
        }

    }

    return 0;
}
