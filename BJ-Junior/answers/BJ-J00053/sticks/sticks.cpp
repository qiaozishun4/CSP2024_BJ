#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int cnt[]={6,2,5,5,4,5,6,3,7,6};
void slv(){
    cin>>n;
    if(n%7==1){
        if(n<8){
            cout<<-1<<endl;
            return;
        }
        cout<<10;
        n-=8;
    }
    else if(n%7==2){
        cout<<1;
        n-=2;
    }
    else if(n%7==3){
        if(n<10){
            cout<<7<<endl;
            return;
        }
        if(n<17){
            cout<<22<<endl;
            return;
        }
        cout<<200;
        n-=17;
    }
    else if(n%7==4){
        if(n<11){
            cout<<4<<endl;
            return;
        }
        cout<<20;
        n-=11;
    }
    else if(n%7==5){
        cout<<2;
        n-=5;
    }
    else if(n%7==6){
        cout<<6;
        n-=6;
    }
        while(n){
            cout<<8;
            n-=7;
        }
        cout<<endl;
    return;
}
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    slv();
    return 0;
}