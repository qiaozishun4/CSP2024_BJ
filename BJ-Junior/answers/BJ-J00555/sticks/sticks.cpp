#include<bits/stdc++.h>
using namespace std;

int main (){
    int wdjss;
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>wdjss;
    for(int dhi=1;dhi<=wdjss;dhi++){
        if(dhi!=1)cout<<endl;
        int n;
        cin>>n;
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
        }else if(n%7==6){
            cout<<6;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
        }else if(n%7==5){
            cout<<2;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
        }else if(n%7==4){
            if(n==4){
                cout<<4;
                continue;
            }
            cout<<20;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }

        }else if(n%7==3){
            if(n==3){
                cout<<7;
                continue;
            }
            if(n==10){
                cout<<22;
                continue;
            }
            cout<<200;
            for(int i=1;i<=n/7-2;i++){
                cout<<8;
            }

        }else if(n%7==2){
            cout<<1;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
        }else if(n%7==1){
            if(n==1){
                cout<<-1;
                continue;
            }
            cout<<10;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }


        }


    }
}
