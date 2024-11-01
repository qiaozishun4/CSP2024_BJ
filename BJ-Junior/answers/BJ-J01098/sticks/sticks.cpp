#include<bits/stdc++.h>
using namespace std;
int t;
int n;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int lll=0;lll<t;lll++){
        cin>>n;
        if(n==1){
            cout<<"-1"<<endl;
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
            cout<<5<<endl;
            continue;
        }
        if(n==6){
            cout<<6<<endl;
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<'8';
            }
            cout<<endl;
            continue;
        }
        if(n%7==1){
            int jj=(n-8)/7;
            cout<<10;
            for(int i=1;i<=jj;i++){
                cout<<'8';
            }
            cout<<endl;
            continue;
        }
        if(n%7==2){
            cout<<1;
            n=n-2;
            for(int i=1;i<=n/7;i++){
                cout<<'8';
            }
            cout<<endl;
            continue;
        }
        if(n%7==3){
            cout<<22;
            n=n-10;
            for(int i=1;i<=n/7;i++){
                cout<<'8';
            }
            cout<<endl;
            continue;
        }
        if(n%7==4){
            cout<<20;
            n=n-11;
            for(int i=1;i<=n/7;i++){
                cout<<'8';
            }
            cout<<endl;
            continue;
        }
        if(n%7==5){
            cout<<5;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==6){
            cout<<6;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
    }
    return 0;
}
