#include <bits/stdc++.h>
using namespace std;
int T,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>n;
        int m=n/7;
        if(n%7==0){
            for(int i=1;i<=m;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==1){
            if(m==0){
                cout<<-1<<endl;
                continue;
            }
            cout<<10;
            for(int i=1;i<=m-1;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==2){
            cout<<1;
            for(int i=1;i<=m;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==3){
            if(m==0){
                cout<<7<<endl;
            }
            else if(m==1){
                cout<<22<<endl;
            }
            else{
                cout<<200;
                for(int i=1;i<=m-2;i++){
                    cout<<8;
                }
                cout<<endl;
            }
        }
        else if(n%7==4){
            if(m==0){
                cout<<4<<endl;
            }
            else{
                cout<<20;
                for(int i=1;i<=m-1;i++){
                    cout<<8;
                }
                cout<<endl;
            }
        }
        else if(n%7==5){
            cout<<2;
            for(int i=1;i<=m;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else{
            cout<<6;
            for(int i=1;i<=m;i++){
                cout<<8;
            }
            cout<<endl;
        }
    }
    return 0;
}