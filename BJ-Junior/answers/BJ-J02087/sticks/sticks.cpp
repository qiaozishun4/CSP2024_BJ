#include<bits/stdc++.h>
using namespace std;
int T,n;
int cs[10]={0,0,1,7,4,2,6,8};
int a[114514];
void sove1(){
    if((n-1)%7==0){
        cout<<1;
        for(int i=1;i<=(n-1)/7;i++)
            cout<<8;
        cout<<endl;
    }
    else if(n%7==0){
        for(int i=1;i<=n/7;i++)
            cout<<8;
        cout<<endl;
    }
    else if(n%6==0){
        cout<<6;
        for(int i=1;i<=n/6-1;i++)
            cout<<0;
        cout<<endl;
    }
    else if(n%5==0){
        for(int i=1;i<=n/5;i++)
            cout<<2;
        cout<<endl;
    }
    else if(n%4==0){
        for(int i=1;i<=n/4;i++)
            cout<<4;
        cout<<endl;
    }
    else if(n%3==0){
        for(int i=1;i<=n/3;i++)
            cout<<7;
        cout<<endl;
    }
    else if(n%2==0){
        for(int i=1;i<=n/2;i++)
            cout<<1;
        cout<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n<=50){
            sove1();
        }else if(n<=100000){
            sove1();
        }else{
            sove1();
        }
    }
    return 0;
}
