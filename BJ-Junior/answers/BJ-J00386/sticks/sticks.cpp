#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1) cout<<-1;
        else if(n==4) cout<<11;
        else if(n%7==0){
            for(int i=0;i<n/7;i++) cout<<8;
        }else if(n%7==1){
            cout<<10;
            for(int i=0;i<n/7-1;i++) cout<<8;
        }else if(n%7==2){
            cout<<1;
            for(int i=0;i<n/7;i++) cout<<8;
        }else if(n%7==3){
            cout<<7;
            for(int i=0;i<n/7;i++) cout<<8;
        }else if(n%7==4){
            cout<<20;
            for(int i=0;i<n/7-1;i++) cout<<8;
        }else if(n%7==5){
            cout<<2;
            for(int i=0;i<n/7;i++) cout<<8;
        }else if(n%7==6){
            cout<<6;
            for(int i=0;i<n/7;i++) cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
