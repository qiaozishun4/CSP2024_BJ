#include<bits/stdc++.h>
using namespace std;
long long t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n==1||n==8){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++)cout<<8;
            cout<<endl;
            continue;
        }
        else if(n%7==1&&n>8){
            cout<<1<<0;
            for(int i=1;i<n/7;i++)cout<<8;
            cout<<endl;
            continue;
        }
        if(n>8){
            if(n%7==2) cout<<1<<8;
            else if(n%7==3) cout<<2<<3;
            else if(n%7==4) cout<<2<<0;
            else if(n%7==5) cout<<2<<8;
            else if(n%7==6) cout<<6<<8;
            for(int i=1;i<n/7;i++)cout<<8;
            cout<<endl;
        }
        else{
            if(n==2) cout<<1<<endl;
            else if(n==3) cout<<7<<endl;
            else if(n==4) cout<<4<<endl;
            else if(n==5) cout<<2<<endl;
            else if(n==6) cout<<6<<endl;
        }
    }
    return 0;
}
