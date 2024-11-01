#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long T,n[60];
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n[i];
    }
    for(int i=0;i<T;i++){
        if(n[i]==0||n[i]==1){
            cout<<-1;
        }
        if(n[i]<=7){
        if(n[i]==2){
            cout<<1;

        }
        if(n[i]==5){
            cout<<2;

        }
        if(n[i]==4){
            cout<<4;

        }
        if(n[i]==6){
            cout<<6;

        }
        if(n[i]==3){
            cout<<7;

        }
        if(n[i]==7){
            cout<<8;

        }
        }
    cout<<endl;
    }
    return 0;
}
