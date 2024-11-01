#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int pt=1;pt<=t;pt++){
        cin>>n;
        if(n==1){
            cout<<-1<<"\n";
        }
        else if(n==2){
            cout<<1<<"\n";
        }
        else if(n==3){
            cout<<7<<"\n";
        }
        else if(n==4){
            cout<<4<<"\n";
        }
        else if(n==5){
            cout<<2<<"\n";
        }
        else if(n==6){
            cout<<6<<"\n";
        }
        else if(n==7){
            cout<<8<<"\n";
        }
        else if(n==8){
            cout<<10<<"\n";
        }
        else if(n==9){
            cout<<18<<"\n";
        }
        else if(n==10){
            cout<<22<<"\n";
        }
        else if(n==11){
            cout<<20<<"\n";
        }
        else if(n==12){
            cout<<28<<"\n";
        }
        else if(n==13){
            cout<<68<<"\n";
        }
        else if(n==14){
            cout<<88<<"\n";
        }
        else if(n==15){
            cout<<108<<"\n";
        }
        else if(n==16){
            cout<<188<<"\n";
        }
        else if(n==17){
            cout<<200<<"\n";
        }
        else if(n==18){
            cout<<208<<"\n";
        }
        else if(n==19){
            cout<<288<<"\n";
        }
        else if(n==20){
            cout<<688<<"\n";
        }
        else if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<"\n";
        }
        else if(n%7==1){
            cout<<10;
            for(int i=1;i<=(n-1)/7-1;i++){
                cout<<8;
            }
            cout<<"\n";
        }
        else if(n%7==2){
            cout<<1;
            for(int i=1;i<=(n-2)/7;i++){
                cout<<8;
            }
            cout<<"\n";
        }
        else if(n%7==3){
            cout<<22;
            for(int i=1;i<=(n-3)/7-1;i++){
                cout<<8;
            }
            cout<<"\n";
        }
        else if(n%7==4){
            cout<<26;
            for(int i=1;i<=(n-4)/7-1;i++){
                cout<<8;
            }
            cout<<"\n";
        }
        else if(n%7==5){
            cout<<2;
            for(int i=1;i<=(n-5)/7;i++){
                cout<<8;
            }
            cout<<"\n";
        }
        else if(n%7==6){
            cout<<6;
            for(int i=1;i<=(n-6)/7;i++){
                cout<<8;
            }
            cout<<"\n";
        }
    }
    return 0;
}
