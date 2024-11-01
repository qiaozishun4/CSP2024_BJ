#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long t;
    cin>>t;
    while(t--){
        long long n,cnt=0,f=0;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++)cout<<8;
            cout<<endl;
            continue;
        }else if(n%7==1){
            cout<<10;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }else if(n%7==2){
            cout<<1;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }else if(n%7==3){
            if(n==3)cout<<7;
            else if(n==10)cout<<22;
            else{
                cout<<200;
                for(int i=1;i<=n/7-2;i++){
                    cout<<8;
                }
            }
            cout<<endl;
            continue;
        }else if(n%7==4){
            if(n==4)cout<<4;
            else{
                cout<<20;
                for(int i=1;i<=n/7-1;i++)cout<<8;
            }
            cout<<endl;
            continue;
        }else if(n%7==5){
            cout<<2;
            for(int i=1;i<=n/7;i++)cout<<8;
            cout<<endl;
            continue;
        }else{
            cout<<6;
            for(int i=1;i<=n/7;i++)cout<<8;
            cout<<endl;
            continue;
        }
    }
    return 0;
}
