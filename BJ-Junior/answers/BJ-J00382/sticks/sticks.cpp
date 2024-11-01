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
    if(n<=1){
        cout<<-1<<endl;
        continue;
    }
    if(n==3){
        cout<<7<<endl;
        continue;
    }
    if(n==4){
        cout<<4<<endl;
        continue;
    }
    if(n%7==0){
        n/=7;
        for(int j=0;j<n;j++){
            cout<<8;
        }
        cout<<endl;
        continue;
    }
    if(n%7==1){
        n=n/7-1;
        cout<<10;
        for(int j=0;j<n;j++){
            cout<<8;
        }
        cout<<endl;
        continue;
    }
    if(n%7==2){
        n/=7;
        cout<<1;
        for(int j=0;j<n;j++){
            cout<<8;
        }
        cout<<endl;
        continue;
    }
    if(n%7==3){
        n=n/7-1;
        cout<<23;
        for(int j=0;j<n;j++){
            cout<<8;
        }
        cout<<endl;
        continue;
    }
    if(n%7==4){
        n=n/7-1;
        cout<<20;
        for(int j=0;j<n;j++){
            cout<<8;
        }
        cout<<endl;
        continue;
    }
    if(n%7==5){
        n/=7;
        cout<<2;
        for(int j=0;j<n;j++){
            cout<<8;
        }
        cout<<endl;
        continue;
    }
    if(n%7==6){
        n/=7;
        cout<<6;
        for(int j=0;j<n;j++){
            cout<<8;
        }
        cout<<endl;
        continue;
    }
  }
    return 0;
}
