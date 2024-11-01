#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0){
            for(int j=0;j<n/7;j++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==1){
            cout<<10;
            n-=8;
            for(int j=0;j<n/7;j++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==2){
            cout<<1;
            n-=2;
            for(int j=0;j<n/7;j++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==3){
            cout<<7;
            n-=3;
            for(int j=0;j<n/7;j++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==4){
            if(n>=11){
                cout<<20;
                n-=11;
            }else{
                cout<<4;
                n-=4;
            }
            for(int j=0;j<n/7;j++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==5){
            cout<<2;
            n-=5;
            for(int j=0;j<n/7;j++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==6){
            cout<<6;
            n-=6;
            for(int j=0;j<n/7;j++){
                cout<<8;
            }
            cout<<endl;
        }
    }
    return 0;
}
