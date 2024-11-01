#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long t;
    cin>>t;
    for(int i=1;i<=t;i++){
        long long n,ans;
        cin>>n;
        if(n==1){
            cout<<"-1"<<endl;
            continue;
        }
        if(n<7){
            if(n==3){
                cout<<7<<endl;
                continue;
            }
            if(n==2){
                cout<<1<<endl;
                continue;
            }if(n==4){
                cout<<4<<endl;
                continue;
            }if(n==5){
                cout<<2<<endl;
                continue;
            }if(n==6){
                cout<<6<<endl;
                continue;
            }
        }

        if(n%7==0){
            for(int j=1;j<=n/7;j++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==6){
            cout<<6;
            for(int j=1;j<=n/7;j++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        ans=7+n%7;
        if(ans==8){
            cout<<1<<0;
            for(int j=1;j<=n/7-1;j++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(ans==9){
            cout<<1<<8;
            for(int j=1;j<=n/7-1;j++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }if(ans==10){
            cout<<2<<2;
            for(int j=1;j<=n/7-1;j++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }if(ans==11){
            cout<<2<<0;
            for(int j=1;j<=n/7-1;j++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }if(ans==12){
            cout<<2<<8;
            for(int j=1;j<=n/7-1;j++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
    }
}
