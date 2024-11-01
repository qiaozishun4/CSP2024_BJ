#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n<2){
            cout<<-1;
            cout<<endl;
            continue;
        }
        if(n%7==0){
            for(int j=1;j<=n/7;j++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==1){
            cout<<10;
            if(n==8){
                    cout<<endl;
                continue;
            }
            for(int j=1;j<=(n-8)/7;j++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==2){
            if(n==2){
                cout<<1;
                cout<<endl;
                continue;
            }
            for(int j=1;j<=(n-2)/7;j++){
                cout<<8;
            }cout<<endl;
            continue;

        }
        if(n%7==3){
            if(n==3){
                cout<<7;
                cout<<endl;
                continue;
            }
            if(n==10){
                cout<<22;
                cout<<endl;
                continue;
            }
            cout<<22;
            for(int j=1;j<=(n-10)/7;j++){
                cout<<8;
            }cout<<endl;
            continue;
        }
        if(n%7==4){
            if(n==4){
                cout<<4;
                cout<<endl;
                continue;
            }
            cout<<20;
            if(n>11){
                for(int j=1;j<=(n-11)/7;j++){
                    cout<<8;
                }
            }cout<<endl;
            continue;
        }
        if(n%7==5){
            cout<<2;
            if(n>5){
                for(int j=1;j<=(n-5)/7;j++){
                    cout<<8;
                }
            }cout<<endl;
            continue;
        }
        if(n%7==6){
            cout<<6;
            if(n>6){
                for(int j=1;j<=(n-6)/7;j++){
                    cout<<8;
                }
            }cout<<endl;
            continue;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
