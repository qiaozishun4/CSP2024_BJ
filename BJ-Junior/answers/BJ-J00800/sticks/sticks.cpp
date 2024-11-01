#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int m=n%7,k=n/7;
        if(n<=1){
            cout<<-1<<'\n';
            continue;
        }
        if(n==4){
            cout<<4<<'\n';
            continue;
        }
        if(n==3){
            cout<<7<<'\n';
            continue;
        }
        if(m==1){
            cout<<10;
            for(int i=0;i<k-1;i++)cout<<8;
        }
        if(m==2){
            cout<<1;
            for(int i=0;i<k;i++)cout<<8;
        }
        if(m==3){
            cout<<22;
            for(int i=0;i<k-1;i++)cout<<8;
        }
        if(m==4){
            cout<<20;
            for(int i=0;i<k-1;i++)cout<<8;
        }
        if(m==5){
            cout<<2;
            for(int i=0;i<k;i++)cout<<8;
        }
        if(m==6){
            cout<<6;
            for(int i=0;i<k;i++)cout<<8;
        }
        if(m==0){
            for(int i=0;i<k;i++)cout<<8;
        }
        cout<<'\n';
    }
    return 0;
}
