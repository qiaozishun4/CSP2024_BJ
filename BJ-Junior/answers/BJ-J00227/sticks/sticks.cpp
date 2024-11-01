#include<bits/stdc++.h>
using namespace std;
int t,n;
int num[11]={6,2,5,5,4,5,6,3,7,6};
int cnt[11]={-1,-1,1,7,4,2,6,8};
int a[50];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=7){
            cout<<cnt[n]<<endl;
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++)cout<<8;
        }
        if(n%7==1){
            cout<<1<<0;
            for(int i=1;i<=(n-8)/7;i++)cout<<8;
        }
        if(n%7==2){
            cout<<1;
            for(int i=1;i<=(n-2)/7;i++)cout<<8;
        }
        if(n%7==3){
            cout<<2<<2;
            for(int i=1;i<=(n-10)/7;i++)cout<<8;
        }
        if(n%7==4){
            cout<<2<<0;
            for(int i=1;i<=(n-11)/7;i++)cout<<8;
        }
        if(n%7==5){
            cout<<2;
            for(int i=1;i<=(n-5)/7;i++)cout<<8;
        }
        if(n%7==6){
            cout<<6;
            for(int i=1;i<=(n-6)/7;i++)cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
