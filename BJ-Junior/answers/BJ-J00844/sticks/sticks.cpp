#include<bits/stdc++.h>
using namespace std;
int a,b;
bool flag;
void apply(int x){
    if(x==0)return;
    if(flag==true&&x>=6&&x!=7){
        cout<<0;
        apply(x-6);
    }
    if(x==6){
        cout<<6;
        apply(x-6);
    }
    if(x==7){
        cout<<8;
        apply(x-7);
    }
    if(x==5){
        cout<<2;
        apply(x-5);
    }
    if(x==4){
        cout<<4;
        apply(x-4);
    }
    if(x==3){
        cout<<7;
        apply(x-3);
    }
    if(x==2){
        cout<<1;
        apply(x-2);
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>a;
    for(int i=0;i<a;i++){
        flag=false;
        cin>>b;
        if(b==1){
            cout<<-1<<"\n";
            continue;
        }
        if(b==5||b>7){
            cout<<2;
            flag=true;
            b-=5;
        }
        apply(b);
        cout<<"\n";
    }
}