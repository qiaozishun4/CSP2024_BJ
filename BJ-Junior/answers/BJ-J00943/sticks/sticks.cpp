#include<iostream>
using namespace std;
int main(){
freopen("sticks.in","r",stdin);
freopen("sticks.out","w",stdout);
int n[51],t;
cin>>t;
for(int i=1;i<=t;i++){
    cin>>n[i];
}
for(int i=1;i<=t;i++){
    if(n[i]%7==0){
    for(int j=1;j<=n[i]/7;j++){
       cout<<8;
    }
    }
    else if(n[i]%7==2){
    cout<<1;
    for(int j=1;j<=n[i]/7;j++){
       cout<<8;
    }
    }
    else if(n[i]%7==1&&n[i]>7){
       cout<<10;
       for(int j=1;j<=(n[i]-8)/7;j++){
          cout<<8;
       }
    }
    else if(n[i]%7==3&&n[i]>14){
       cout<<200;
       for(int j=i;j<=(n[i]-17)/7;j++){
          cout<<8;
       }
    }
    else if(n[i]%7==4&&n[i]>7){
        cout<<20;
        for(int j=1;j<=(n[i]-11)/7;j++){
           cout<<8;
        }
    }
    else if(n[i]%7==5){
        cout<<2;
        for(int j=1;j<=(n[i]-5)/7;j++){
           cout<<8;
        }
    }
    else if(n[i]%7==6){
        cout<<6;
        for(int j=1;j<=(n[i]-6)/7;j++){
           cout<<8;
        }
    }
    else if(n[i]==1){
        cout<<-1;
    }
    else if(n[i]==3){
        cout<<7;
    }
    else if(n[i]==4){
        cout<<4;
    }
    else if(n[i]==10){
        cout<<22;
    }
    cout<<endl;
}
return 0;
}
