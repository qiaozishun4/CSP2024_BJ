#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int a[10]={-1,-1,1,7,4,2,6},c[10]={6,2,5,5,4,5,6,3,7,6},t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<7) cout<<a[n];
        else if(n%7==0) for(int i=1;i<=n/7;i++) cout<<8;
        else if(n%7==1){
            cout<<10;
            for(int i=1;i<n/7;i++) cout<<8;
        }
        else if(n%7==2){
            cout<<1;
            for(int i=1;i<=n/7;i++) cout<<8;
        }
        else if(n%7==3){
            cout<<22;
            for(int i=1;i<n/7;i++) cout<<8;
        }
        else if(n%7==4){
            cout<<20;
            for(int i=1;i<n/7;i++) cout<<8;
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
