#include<iostream>
using namespace std;
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=1){
            cout<<-1<<endl;
            continue;
        }else if(n<7){
            if(n==2){
                cout<<1;
            }
            if(n==3){
                cout<<7;
            }
            if(n==4){
                cout<<4;
            }
            if(n==5){
                cout<<2;
            }
            if(n==6){
                cout<<6;
            }
            cout<<endl;
            continue;
        }
        if(n%7==3&&n>=17){
            cout<<200;
            for(int i=1;i<=(n-17)/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        int cnt=0;
        cnt=n/7-1;
        n-=(n/7-1)*7;
        if(n==7){
            cout<<8;
        }
        if(n==8){
            cout<<10;
        }
        if(n==9){
            cout<<18;
        }
        if(n==10){
            cout<<22;
        }
        if(n==11){
            cout<<20;
        }
        if(n==12){
            cout<<28;
        }
        if(n==13){
            cout<<68;
        }
        for(int i=1;i<=cnt;i++){
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
