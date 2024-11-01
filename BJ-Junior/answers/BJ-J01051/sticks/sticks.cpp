#include<iostream>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int sticks;
        cin>>sticks;
        if(sticks==6){
            cout<<6;
            cout<<'\n';
            continue;
        }
        if(sticks==1){
            cout<<-1;
            cout<<'\n';
            continue;
        }
        if(sticks%7==0){
            for(int j=sticks;j>=7;j-=7){
                cout<<8;
            }
            cout<<'\n';
//          continue;
        }
        else if(sticks%7==1){
            cout<<1<<0;
            sticks-=8;
            for(int j=sticks;j>=7;j-=7){
                cout<<8;
            }
            cout<<'\n';
        }
        else if(sticks%7==2){
            cout<<1;
            sticks-=2;
            for(int j=sticks;j>=7;j-=7){
                cout<<8;
            }
            cout<<'\n';
        }
        else if(sticks%7==3){
            if(sticks>=10){
                cout<<2<<3;
                sticks-=10;
                for(int j=sticks;j>=7;j-=7){
                    cout<<8;
                }
                cout<<'\n';
            }
            else{
                cout<<7<<'\n';
            }
        }
        else if(sticks%7==4){
            if(sticks>=11){
                cout<<2<<0;
                sticks-=11;
                for(int j=sticks;j>=7;j-=7){
                    cout<<8;
                }
                cout<<'\n';
            }
            else{
                cout<<4<<'\n';
            }
        }
        else if(sticks%7==5){
            cout<<2;
            sticks-=5;
            for(int j=sticks;j>=7;j-=7){
                cout<<8;
            }
            cout<<'\n';
        }
        else{
            cout<<6;
            sticks-=6;
            for(int j=sticks;j>=7;j-=7){
                cout<<8;
            }
            cout<<'\n';
        }
    }
    return 0;
}
