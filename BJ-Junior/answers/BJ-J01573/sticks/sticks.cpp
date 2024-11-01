#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long num[15]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(long long i=1;i<=t;i++){
        cin>>n;
        if(n<2){
            cout<<-1;
            continue;
        }else if(n==2){
            cout<<1;
            continue;
        }else if(n==3){
            cout<<7;
            continue;
        }else if(n==4){
            cout<<4;
            continue;
        }else if(n==5){
            cout<<2;
            continue;
        }else if(n==6){
            cout<<6;
            continue;
        }else{
            if((n-1)%7==0){
                cout<<10;
                long long tmp=(n-8)/7;
                for(long long j=1;j<=tmp;j++){
                    cout<<8;
                }
                continue;
            }
            if(n%2==0){
                long long tmp=n/2;
                for(long long j=1;j<=tmp;j++){
                    cout<<1;
                }
                continue;
            }
            if((n-1)%2==0){
                long long tmp=(n-3)/7;
                for(long long j=1;j<=tmp;j++){
                    cout<<1;
                }
                cout<<7;
                continue;
            }
            if((n-1)%5==0){
                long long tmp=(n-6)/5;
                for(long long j=1;j<=tmp;j++){
                    cout<<2;
                }
                cout<<0;
                break;
            }
            if(n%5==0){
                long long tmp=n/5;
                for(long long j=1;j<=tmp;j++){
                    cout<<2;
                }
                continue;
            }
            if((n-1)%4==0){
                cout<<2;
                long long tmp=(n-5)/4;
                for(long long j=1;j<=tmp;j++){
                    cout<<4;
                }
                continue;
            }
            if(n%4==0){
                long long tmp=n/4;
                for(long long j=1;j<=tmp;j++){
                    cout<<4;
                }
                continue;
            }
            if((n-1)%3==0){
                cout<<4;
                long long tmp=(n-4)/3;
                for(long long j=1;j<=tmp;j++){
                    cout<<7;
                }
                break;
            }
            if(n%6==0){
                long long tmp=n/6;
                cout<<6;
                for(long long j=1;j<=tmp-1;j++){
                    cout<<0;
                }
                continue;
            }
            if((n-1)%6==0){
                cout<<6;
                long long tmp=(n-7)/6;
                for(long long j=1;j<=tmp-1;j++){
                    cout<<0;
                }
                cout<<8;
                continue;
            }
            if(n%3==0){
                long long tmp=n/3;
                for(long long j=1;j<=tmp;j++){
                    cout<<7;
                }
                continue;
            }
            if(n%7==0){
                long long tmp=n/7;
                for(long long j=1;j<=tmp;j++){
                    cout<<8;
                }
                continue;
            }
        }
        cout<<endl;
    }
}