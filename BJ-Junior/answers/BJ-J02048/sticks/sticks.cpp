#include<bits/stdc++.h>
using namespace std;

long long T, n;

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin>>T;
    while(T--){
        cin>>n;
        int k = n / 7;
        if(n < 7){
            if(n == 2){
                cout<<1;
            }else if(n == 4){
                cout<<4;
            }else if(n == 5){
                cout<<2;
            }else if(n == 3){
                cout<<7;
            }else if(n == 6){
                cout<<6;
            }else{
                cout<<-1;
            }
            cout<<endl;
            continue;
        }
        if(n % 7 == 0){
            for(int i = 1; i <= k; i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n % 7  >= 1){
            if(n%7 == 1){
                cout<<10;
            }else if(n % 7 == 2){
                cout<<18;
            }else if(n % 7 == 3){
                cout<<22;
            }else if(n % 7 == 4){
                cout<<20;
            }else if(n % 7 == 5){
                cout<<28;
            }else if(n % 7 == 6){
                cout<<68;
            }
            for(int i = 1; i <= k-1; i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
    }
    return 0;
}
