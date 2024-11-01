#include <bits/stdc++.h>
using namespace std;
int smaller_than_7[10] = {-1,-1,1,7,4,2,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n < 7){
            cout<<smaller_than_7[n]<<endl;
            continue;
        }
        if(n % 7 == 0){
            for(int i = 1; i <= n/7; i++){
                cout<<8;
            }
            cout<<endl;
        }
        if(n % 7 == 1){
            cout<<10;
            for(int i = 1; i <= (n-8)/7; i++){
                cout<<8;
            }
            cout<<endl;
        }
        if(n % 7 == 2){
            cout<<18;
            for(int i = 1; i <= (n-9)/7; i++){
                cout<<8;
            }
            cout<<endl;
        }
        if(n % 7 == 3){
            if(n == 10){
                cout<<22<<endl;
            }else{
                cout<<200;
                for(int i = 1; i <= (n-17)/7; i++){
                    cout<<8;
                }
                cout<<endl;
            }
        }
        if(n % 7 == 4){
            cout<<20;
            for(int i = 1; i <= (n-11)/7; i++){
                cout<<8;
            }
            cout<<endl;
        }
        if(n % 7 == 5){
            cout<<28;
            for(int i = 1; i <= (n-12)/7; i++){
                cout<<8;
            }
            cout<<endl;
        }
        if(n % 7 == 6){
            cout<<68;
            for(int i = 1; i <= (n-13)/7; i++){
                cout<<8;
            }
            cout<<endl;
        }
    }
}
