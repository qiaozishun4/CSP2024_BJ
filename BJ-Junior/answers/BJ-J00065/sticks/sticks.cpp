#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    //int num[10]={6,2,5,5,4,5,6,3,7,6};
    //int nu[10]={0,1,2,3,4,5,6,7,8,9};
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1) cout<<-1;
        else if(n==2) cout<<1;
        else if(n==3) cout<<7;
        else if(n==4) cout<<4;
        else if(n==5) cout<<2;
        else if(n==6) cout<<6;
        else if(n%7==0){
            for(int i=1;i<=n/7;i++) cout<<8;
        }
        else if(n%7==1){
            cout<<10;
            for(int i=2;i<=n/7;i++) cout<<8;
        }
        else if(n%7==2){
            cout<<1;
            for(int i=1;i<=n/7;i++) cout<<8;
        }
        else if(n%7==3){
            cout<<22;
            for(int i=2;i<=n/7;i++) cout<<8;
        }
        else if(n%7==4){
            cout<<20;
            for(int i=2;i<=n/7;i++) cout<<8;
        }
        else if(n%7==5){
            cout<<2;
            for(int i=1;i<=n/7;i++) cout<<8;
        }
        else if(n%7==6){
            cout<<6;
            for(int i=1;i<=n/7;i++) cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
