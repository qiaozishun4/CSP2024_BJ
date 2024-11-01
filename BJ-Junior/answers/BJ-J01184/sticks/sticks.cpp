#include <bits/stdc++.h>
using namespace std;
int T;
int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
//12,8,11,10,12,9,13,12,6,7,5,4,8,14
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i = 1;i<=9;i++){
            if(a[i] == n){
                cout<<i;
                goto net;
            }
        }
        if(n/10 == 0){
            cout<<-1;
            goto net;
        }
        if(n%7 == 0){
            for(int i = 1;i<=n/7;i++){
                cout<<8;
            }
        }
        else if(n%7 == 1){
            cout<<1<<0;
            for(int i = 1;i<=(n-8)/7;i++){
                cout<<8;
            }
        }
        else if(n%7 == 2){
            cout<<1<<8;
            for(int i = 1;i<=(n-9)/7;i++){
                cout<<8;
            }
        }
        else if(n%7 == 3){
            cout<<2<<2;
            for(int i = 1;i<=(n-10)/7;i++){
                cout<<8;
            }
        }
        else if(n%7 == 4){
            cout<<2<<0;
            for(int i = 1;i<=(n-11)/7;i++){
                cout<<8;
            }
        }
        else if(n%7 == 5){
            cout<<3<<8;
            for(int i = 1;i<=(n-12)/7;i++){
                cout<<8;
            }
        }
        else if(n%7 == 6){
            cout<<6<<8;
            for(int i = 1;i<=(n-13)/7;i++){
                cout<<8;
            }
        }
        cout<<'\n';
        net:
        cout<<'\n';
    }
    return 0;
}
