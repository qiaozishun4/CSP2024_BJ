#include<bits/stdc++.h>
using namespace std;
int t,n,a[8]={0,-1,1,7,4,2,6,8};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int t=n/7;
        if(n<=8){
            cout<<a[n]<<'\n';
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=t;++i) cout<<8;
            cout<<'\n';
        }
        else if(n%7==1){
            t--;
            cout<<10;
            for(int i=1;i<=t;++i) cout<<8;
            cout<<'\n';
        }
        else if(n%7==2){
            cout<<1;
            for(int i=1;i<=t;++i) cout<<8;
            cout<<'\n';
        }
        else if(n%7==3){
            t--;
            cout<<22;
            for(int i=1;i<=t;++i) cout<<8;
            cout<<'\n';
        }
        else if(n%7==4){
            t--;
            cout<<20;
            for(int i=1;i<=t;++i) cout<<8;
            cout<<'\n';
        }
        else if(n%7==5){
            cout<<2;
            for(int i=1;i<=t;++i) cout<<8;
            cout<<'\n';
        }
        else{
            cout<<6;
            for(int i=1;i<=t;++i) cout<<8;
            cout<<'\n';
        }
    }
    return 0;
}