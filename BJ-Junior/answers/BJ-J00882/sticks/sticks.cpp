#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int a=0;a<T;a++){
        int n;
        int wei;
        int ex;
        cin>>n;
        if(n%7==0){
            wei=n/7;
        }
        else{
            wei=(n/7)+1;
        }
        ex=7-(n%7);
        if(ex==7){
            for(int i=0;i<wei;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(ex==6){
            wei=wei-2;
            if(wei<0){
                cout<<-1<<endl;
            }
            else {
                cout<<16;
                for(int i=0;i<wei;i++){
                    cout<<8;
                }
                cout<<endl;
            }
        }
        else if(ex==5){
            cout<<1;
            wei=wei-1;
            for(int i=0;i<wei;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(ex==4){
            wei=wei-2;
            if(wei<0){
                wei=wei+1;
                cout<<7;
            }
            else {
                cout<<22;
            }
            for(int i=0;i<wei;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(ex==3){
            wei=wei-2;
            if(wei<0){
                wei=wei+1;
                cout<<4;
            }
            else {
                cout<<20;
            }
            for(int i=0;i<wei;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(ex==2){
            wei=wei-1;
            cout<<2;
            for(int i=0;i<wei;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(ex==1){
            wei=wei-1;
            cout<<6;
            for(int i=0;i<wei;i++){
                cout<<8;
            }
            cout<<endl;
        }
    }
    return 0;
}