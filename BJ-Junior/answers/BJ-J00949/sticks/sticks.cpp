#include<bits/stdc++.h>
using namespace std;//2.3.4.5.6.7
int n,k,a[10]={6,2,5,5,4,5,6,3,7,6},z[10]={-1,-1,1,7,4,3,6,8};
long long b[100010];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>k;
        if(k<=7)    cout<<z[k];
        else if(k%7==0)
            for(;k>0;k-=7)
                cout<<8;
        else if(k%7==2){
            cout<<18;
            k-=k%7+7;
            for(;k>0;k-=7)
                cout<<8;
        }
        else if(k%7==3){
            cout<<22;
            k-=k%7+7;
            for(;k>0;k-=7)
                cout<<8;
        }
        else if(k%7==4){
            cout<<20;
            k-=k%7+7;
            for(;k>0;k-=7)
                cout<<8;
        }
        else if(k%7==5){
            cout<<2;
            k-=k%7;
            for(;k>0;k-=7)
                cout<<8;
        }
        else if(k%7==6){
            cout<<6;
            k-=k%7;
            for(;k>0;k-=7)
                cout<<8;
        }
        else{
            cout<<1<<0;
            k-=8;
            for(;k>0;k-=7)
                cout<<8;
        }
    }
    return 0;
}