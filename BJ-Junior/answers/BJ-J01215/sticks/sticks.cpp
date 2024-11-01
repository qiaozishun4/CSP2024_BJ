#include<bits/stdc++.h>
using namespace std;
int t,ts[7]={-1,-1,1,7,4,2,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    for(cin>>t;t;t--){
        int n,x,y;
        cin>>n;
        x=(n+6)/7;
        if(n<7){
            cout<<ts[n]<<endl;
            continue;
        }
        if(x==10){
            cout<<22;
            continue;
        }
        y=n%7;
        if(y==0) for(int i=1;i<=x;i++) cout<<8;
        if(y==1){
            cout<<10;
            for(int i=1;i<=x-2;i++) cout<<8;
        }
        if(y==2){
            cout<<1;
            for(int i=1;i<x;i++) cout<<8;
        }
        if(y==3){
            cout<<200;
            for(int i=1;i<=x-2;i++) cout<<8;
        }
        if(y==4){
            cout<<20;
            for(int i=1;i<=x-2;i++) cout<<8;
        }
        if(y==5){
            cout<<2;
            for(int i=1;i<x;i++) cout<<8;
        }
        if(y==6){
            cout<<6;
            for(int i=1;i<x;i++) cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
