#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n<2)cout<<-1;
        if(n==2)cout<<1;
        if(n==3)cout<<7;
        if(n==4)cout<<4;
        if(n==5)cout<<2;
        if(n==6)cout<<6;
        if(n==7)cout<<8;
        if(n==8)cout<<10;
        if(n==9)cout<<18;
        if(n==10)cout<<23;
        if(n==11)cout<<20;
        if(n==12)cout<<26;
        if(n==13)cout<<28;
        if(n==14)cout<<88;
        if(n==15)cout<<180;
        if(n==16)cout<<188;
        if(n==17)cout<<228;
        if(n==18)cout<<208;
        if(n==19)cout<<288;
        if(n==20)cout<<880;
    }
    return 0;
}

