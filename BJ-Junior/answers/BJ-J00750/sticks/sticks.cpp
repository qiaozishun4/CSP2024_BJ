#include<iostream>
#include<cstring>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n[1005];
    cin>>T;
    int j;
    for(int i=1;i<=T;i++){
        cin>>n[i];
    }
    for(int i=1;i<=T;i++){
        if(n[i]<=7){
               if(n[i]==1)  cout<<-1;
               if(n[i]==2) cout<<1;
               if(n[i]==3) cout<<7;
               if(n[i]==4) cout<<4;
               if(n[i]==5) cout<<2;
               if(n[i]==6) cout<<6;
               if(n[i]==7) cout<<8;
               cout<<endl;
        }
        else{
        if(n[i]%7==0){
            for(int j=1;j<=n[i]/7;j++) cout<<8;
        }
        if(n[i]%7==1){
             cout<<12;
            for(int j=3;j<=n[i]/7+1;j++) cout<<8;
        }
        if(n[i]%7==2){
                cout<<1;
            for(int j=2;j<=n[i]/7+1;j++) cout<<8;
        }
        if(n[i]%7==3){
              cout<<22;
            for(int j=3;j<=n[i]/7+1;j++) cout<<8;
        }
        if(n[i]%7==4){
            cout<<20;
            for(int j=3;j<=n[i]/7+1;j++) cout<<8;
        }
        if(n[i]%7==5){
           cout<<2;
            for(int j=2;j<=n[i]/7+1;j++) cout<<8;
        }
        if(n[i]%7==6){
    cout<<6;
        for(int j=2;j<=n[i]/7+1;j++) cout<<8;
        }
        cout<<endl;
        }
    }

return 0;
}
