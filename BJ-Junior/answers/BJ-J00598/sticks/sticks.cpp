#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){

    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        cin>>n;
        int k;//k, num of numbers
        if(n%7==0) k=n/7;
        else k=n/7+1;
        if(n==1){
            cout<<-1<<'\n';
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=k;i++) cout<<8;
            cout<<'\n';
            continue;
        }else if(n%7==1){
            cout<<10;
            for(int i=1;i<=k-2;i++) cout<<8;
            cout<<'\n';
            continue;
        }else if(n%7==2){
            cout<<1;
            for(int i=1;i<=k-1;i++) cout<<8;
            cout<<'\n';
            continue;
        }else if(n%7==5){
            cout<<2;
            for(int i=1;i<=k-1;i++) cout<<8;
            cout<<'\n';
            continue;
        }else if(n==6){
            cout<<6<<'\n';
            continue;
        }else if(n%7==6){
            cout<<6;
            for(int i=1;i<=k-1;i++) cout<<8;
            cout<<'\n';
            continue;
        }else if(n==4){
            cout<<4<<'\n';
            continue;
        }else if(n%7==4){
            cout<<20;
            for(int i=1;i<=k-2;i++) cout<<8;
            cout<<'\n';
            continue;
        }else if(n==3){
            cout<<7<<'\n';

            continue;
        }else if(n%14==10){
            cout<<22;
            for(int i=1;i<=k-2;i++) cout<<8;
            cout<<'\n';
            continue;
        }else if(n%14==3){
            cout<<200;
            for(int i=1;i<=k-3;i++) cout<<8;
            continue;
        }
    }
    return 0;

}
