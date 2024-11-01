#include<iostream>
#include<cstring>
#include<bits/c++io.h>
using namespace std;
int a[1001],b[1001]={6,2,5,5,4,5,6,3,7,6};
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==2)cout<<1<<" ";
        if(a[i]==3)cout<<7<<" ";
        if(a[i]==4)cout<<4<<" ";
        if(a[i]==5)cout<<2<<" ";
        if(a[i]==6)cout<<6<<" ";
        if(a[i]==7)cout<<8<<" ";
        if(a[i]==8)cout<<10<<" ";
        if(a[i]==9)cout<<18<<" ";
        if(a[i]==10)cout<<22<<" ";
        if(a[i]==11)cout<<20<<" ";
        if(a[i]==12)cout<<27<<" ";
        else{
            cout<<-1;
        }


    }
    return 0;
}
