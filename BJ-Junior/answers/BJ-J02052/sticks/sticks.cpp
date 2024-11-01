#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout << 8;
            }
        }
        else if(n%7==1){
            if(n==1){
                cout << -1;
            }
            else{
                cout << 10;
                for(int i=1;i<n/7;i++){
                    cout << 8;
                }
            }
        }
        else if(n%7==2){
            cout << 1;
            for(int i=1;i<=n/7;i++){
                cout << 8;
            }
        }
        else if(n%7==3){
            if(n==3){
                cout << 7;
            }
            else if(n==10){
                cout << 22;
            }
            else{
                cout << 200;
                for(int i=1;i<=n/7-2;i++){
                    cout << 8;
                }
            }
        }
        else if(n%7==4){
            if(n==4){
                cout << 4;
            }
            else{
                cout << 20;
            }
            for(int i=1;i<n/7;i++){
                cout << 8;
            }
        }
        else if(n%7==5){
            cout << 2;
            for(int i=1;i<=n/7;i++){
                cout << 8;
            }
        }
        else if(n%7==6){
            cout << 6;
            for(int i=1;i<=n/7;i++){
                cout << 8;
            }
        }
        cout << endl;
    }
    return 0;
}
/*
6 2 5 ? 4 ? 6 3 7 ?
0 1 2 3 4 5 6 7 8 9

0 1 2 4 3 7
*/
