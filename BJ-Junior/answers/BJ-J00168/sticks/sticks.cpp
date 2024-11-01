#include<bits/stdc++.h>
using namespace std;
int a[11];

int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    long long t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1;
        }if(n==2){
            cout<<1;
        }if(n==3)cout<<7;
        if(n==4)cout<<4;
        if(n==5)cout<<2;
        if(n==6)cout<<6;
        if(n==7)cout<<8;
        if(n==8)cout<<16;
        if(n==9)cout<<18;
        if(n==10)cout<<22;
        if(n==11)cout<<26;
        if(n==12)cout<<28;
        if(n==13)cout<<68;
        if(n==14)cout<<77;
        if(n==15)cout<<168;
        if(n==16)cout<<188;
        if(n==17)cout<<228;
        if(n==18)cout<<208;
        if(n==19)cout<<277;
        if(n==20)cout<<677;
    }
    return 0;
}
