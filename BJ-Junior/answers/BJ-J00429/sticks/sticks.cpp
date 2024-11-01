#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n==1){
            cout<<-1;
        }else if(n==2){
            cout<<1;
        }else if(n==3){
            cout<<7;
        }else if(n==4){
            cout<<4;
        }else if(n==5){
            cout<<2;
        }else if(n==6){
            cout<<0;
        }else if(n==7){
            cout<<8;
        }
    }
    return 0;
}
