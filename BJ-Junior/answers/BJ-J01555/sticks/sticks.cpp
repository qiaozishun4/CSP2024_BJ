#include<bits/stdc++.h>
using namespace std;
long long n;
long long mg[]={6,2,5,5,4,5,6,3,7,6};
long long f(long long n){
    long long x=n/7;
    long long sum=0;
    while(x--){
        sum=sum*10+8;
    }
    return sum;
}
long long e(long long n){
    long long x=n/2+1;
    long long sum=0;
    while(x--){
        sum=sum*10+1;
    }
    return sum;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
    bool b=0;
    cin>>n;
    if(n<=1){
        cout<<-1<<endl;
    }
    else{
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }
        if(n%7==1){
            cout<<10;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
            cout<<endl;
        }
        if(n%7==2){
            cout<<1;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }
        if(n%7==3){
            if(n<=10){
            cout<<7;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            }else{
                cout<<200;
            for(int i=1;i<=n/7-2;i++){
                cout<<8;
            }
            cout<<endl;
            }
        }
        if(n%7==4){
            cout<<20;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
            cout<<endl;
        }
        if(n%7==5){
            cout<<2;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }
        if(n%7==6){
            cout<<6;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }
    }}
}
