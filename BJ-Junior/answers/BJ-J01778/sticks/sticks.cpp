#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int t=1;t<=T;t++){
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
        }else if(n%7==0){//8  0
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==1){//10+8  1
            cout<<10;
            for(int i=1;i<=(n-8)/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==2){//1+8  2
            cout<<1;
            for(int i=1;i<=(n-2)/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==3&&n>=17){//200+8  3
            cout<<200;
            for(int i=1;i<=(n-17)/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==4&&n>=11){//20+8  4
            cout<<20;
            for(int i=1;i<=(n-11)/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==5){//2+8  5
            cout<<2;
            for(int i=1;i<=(n-5)/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==6){//6+8  6
            cout<<6;
            for(int i=1;i<=(n-6)/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else{//sheng
            if(n==3)cout<<7<<endl;
            if(n==4)cout<<4<<endl;
            if(n==10)cout<<22<<endl;
        }
    }
    return 0;
}
