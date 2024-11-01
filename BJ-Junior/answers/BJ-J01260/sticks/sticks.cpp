#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[15]={6,2,5,5,4,5,6,3,7,6},T,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n==1) cout<<-1;
        else if(n==2) cout<<1;
        else if(n==3) cout<<7;
        else if(n==4) cout<<4;
        else if(n==5) cout<<2;
        else if(n==6) cout<<6;
        else if(n==10) cout<<22;
        else if(n%7==0) for(int i=1;i<=n/7;i++) cout<<8;
        else if(n%7==1){
            cout<<1<<0;
            for(int i=1;i<=n/7-1;i++) cout<<8;
        }
        else if(n%7==2){
            cout<<1;
            for(int i=1;i<=n/7;i++) cout<<8;
        }
        else if(n%7==4){
            cout<<2<<0;
            for(int i=1;i<=n/7-1;i++) cout<<8;
        }
        else if(n%7==5){
            cout<<2;
            for(int i=1;i<=n/7;i++) cout<<8;
        }
        else if(n%7==6){
            cout<<6;
            for(int i=1;i<=n/7;i++) cout<<8;
        }
        else if(n%7==3){
            cout<<2<<0<<0;
            for(int i=1;i<=n/7-2;i++) cout<<8;
        }
        cout<<endl;
    }
    return 0;
}