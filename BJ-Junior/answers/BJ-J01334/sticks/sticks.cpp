#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%7==1){
            if(n==1){
                cout<<-1<<endl;
                continue;
            }
            cout<<10;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n<7){
            if(n==2){
                cout<<1<<endl;
            }
            if(n==3){
                cout<<7<<endl;
            }
            if(n==4){
                cout<<4<<endl;
            }
            if(n==5){
                cout<<2<<endl;
            }
            if(n==6){
                cout<<6<<endl;
            }
            continue;
        }
        if(n%7==2){
            cout<<1;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==3){
            if(n==10){
                cout<<22<<endl;
                continue;
            }
            cout<<200;
            for(int i=1;i<=n/7-2;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==4){
            cout<<20;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==5){
            cout<<28;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==6){
            cout<<68;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
    }
    return 0;
}
