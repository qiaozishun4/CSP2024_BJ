#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(n>=7){
            if(n%7==0){
                for (int i = 1; i <= n/7; i++){
                    cout << 8;
                }
                cout <<endl;
            }else if(n%7==1){
                cout <<10;
                n-=8;
                for (int i = 1; i <= n/7; i++){
                    cout <<8;
                }
                cout <<endl;
            }else if(n%7==2){
                cout <<1;
                n-=2;
                for (int i = 1; i <= n/7; i++){
                    cout <<8;
                }
                cout <<endl;
            }else if(n%7==3){
                cout <<22;
                n-=10;
                for (int i = 1; i <= n/7; i++){
                    cout <<8;
                }
                cout <<endl;
            }else if(n%7==4){
                cout <<20;
                n-=11;
                for (int i = 1; i <= n/7; i++){
                    cout <<8;
                }
                cout <<endl;
            }
            else if(n%7==5){
                cout <<2;
                n-=5;
                for (int i = 1; i <= n/7; i++){
                    cout <<8;
                }
                cout <<endl;
            }else if(n%7==6){
                cout <<80;
                n-=13;
                for (int i = 1; i <= n/7; i++){
                    cout <<8;
                }
                cout <<endl;
            }
        }else{
            if(n==1){
                cout <<-1;
            }else if(n==2){
                cout <<1;
            }else if(n==3){
                cout <<7;
            }else if(n==4){
                cout <<4;
            }else if(n==5){
                cout <<2;
            }else if(n==6){
                cout <<6;
            }
            cout <<endl;
        }
    }
    return 0;
}