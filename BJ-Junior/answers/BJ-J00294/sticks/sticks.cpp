#include <bits/stdc++.h>
using namespace std;
long long T,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int j = 0;j<T;j++){
        cin>>n;
        if(n==0||n==1)cout<<"-1"<<endl;
        else if(n%7==1){
            cout<<10;
            for(int i = 1;i<(n-n%7)/7;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==0){
            for(int i = 0;i<n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==2){
            //the less number:1
            cout<<1;
            for(int i = 0;i<(n-n%7)/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==3){
            //the less number:2
            if((n-n%7)/7==0)cout<<7<<endl;
            else if((n-n%7)/7==1)cout<<22<<endl;
            else{
                cout<<200;
                for(int i = 2;i<(n-n%7)/7;i++){
                    cout<<8;
                }
                cout<<endl;
            }
        }else if(n%7==4){
            //the less number:2
            if((n-n%7)/7==0)cout<<4<<endl;
            else{
                cout<<20;
                for(int i = 1;i<(n-n%7)/7;i++){
                    cout<<8;
                }
                cout<<endl;
            }
        }else if(n%7==5){
            //the less number:2
            cout<<2;
            for(int i = 0;i<(n-n%7)/7;i++){
                cout<<8;
            }
            cout<<endl;
        }else if(n%7==6){
            cout<<6;
            for(int i = 0;i<(n-n%7)/7;i++)cout<<8;
            cout<<endl;
        }
    }
    return 0;
}
