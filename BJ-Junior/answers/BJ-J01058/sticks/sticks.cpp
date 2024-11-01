#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int _;
    cin >> _;
    while(_--){
        int n;
        cin >> n;
        if(n%7==0){
            while(n>6){
                cout << 8;
                n-=7;
            }
        }else if(n%7==1){
            if(n<8){
                cout << -1;
                continue;
            }
            cout << 1 << 0;
            n-=8;
            while(n>6){
                n-=7;
                cout << 8;
            }
        }else if(n%7==2){
            cout << 1;
            n-=2;
            while(n>6){
                cout << 8;
                n-=7;
            }
        }else if(n%7==3){
            if(n==3)cout << 7;
            else{
                cout << 22;
                n-=10;
                while(n>6){
                    n-=7;
                    cout << 8;
                }
            }
        }else if(n%7==4){
            if(n==4)cout << 4;
            else{
                cout << 20;
                n-=11;
                while(n>6){
                    n-=7;
                    cout << 8;
                }
            }
        }else if(n%7==5){
            cout << 2;
            n-=5;
            while(n>6){
                n-=7;
                cout << 8;
            }
        }else{
            cout << 6;
            while(n>6){
                cout << 8;
                n-=7;
            }
        }
        cout << endl;
    }
    return 0;
}
