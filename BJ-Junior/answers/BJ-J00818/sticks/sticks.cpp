#include<bits/stdc++.h>
using namespace std;
long long t,n,a[]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n==2){
            cout<<1<<endl;
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
        if(n==5){
            cout<<2<<endl;
            continue;
        }
        if(n==6){
            cout<<6<<endl;
            continue;
        }
        if(n%7==0){
            for(int i=1; i<=n/7; i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==1){
            cout<<10;
            for(int i=1; i<=n/7-1; i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==2){
            cout<<1;
            for(int i=1; i<=n/7; i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==3){
            cout<<22;
            for(int i=1; i<=n/7-1; i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==4){
            cout<<20;
            for(int i=1; i<=n/7-1; i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==5){
            cout<<2;
            for(int i=1; i<=n/7; i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==6){
            cout<<68;
            for(int i=1; i<=n/7-1; i++){
                cout<<8;
            }
            cout<<endl;
        }
    }
    return 0;
}