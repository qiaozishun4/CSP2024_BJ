#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<7){
            if(n==1) cout<<-1;
            if(n==2) cout<<1;
            if(n==3) cout<<7;
            if(n==4) cout<<4;
            if(n==5) cout<<2;
            if(n==6) cout<<6;
            cout<<endl;
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=(n/7);i++) cout<<8;
        }else if(n%7==1){
            cout<<10;
            for(int i=1;i<=((n-8)/7);i++) cout<<8;
        }else if(n%7==2){
            cout<<18;
            for(int i=1;i<=((n-9)/7);i++) cout<<8;
        }else if(n%7==3){
            cout<<23;
            for(int i=1;i<=((n-10)/7);i++) cout<<8;
        }else if(n%7==4){
            cout<<20;
            for(int i=1;i<=((n-11)/7);i++) cout<<8;
        }else if(n%7==5){
            cout<<28;
            for(int i=1;i<=((n-12)/7);i++) cout<<8;
        }else{
            cout<<68;
            for(int i=1;i<=((n-13)/7);i++) cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
