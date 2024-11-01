#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int arr[10]={6,2,5,5,4,5,6,3,7,6};
    int n;
    cin>>n;
    int t;
    for(int i=0;i<n;i++){
        cin>>t;
        if(t<2){
            cout<<-1;
            continue;
        }
        if(t==2){
            cout<<1;
            continue;
        }
        if(t==3){
            cout<<7;
            continue;
        }
        if(t==4){
            cout<<4;
            continue;
        }
        if(t==5){
            cout<<2;
            continue;
        }
        if(t==6){
            cout<<6;
            continue;
        }
        int sumba=t/7;
        int sumling=(t%7)/6;
        t=(t%7)%6;
        if(t==0){
            cout<<8;
            sumba--;
            if(sumling==1){
                cout<<0;
            }
            for(int i=0;i<sumba;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(t<2){
            cout<<-1;
            continue;
        }
        if(t==2){
            cout<<1;
            if(sumling==1){
                cout<<0;
            }
            for(int i=0;i<sumba;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(t==3){
            cout<<7;
            if(sumling==1){
                cout<<0;
            }
            for(int i=0;i<sumba;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(t==4){
            cout<<4;
            if(sumling==1){
                cout<<0;
            }
            for(int i=0;i<sumba;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(t==5){
            cout<<2;
            if(sumling==1){
                cout<<0;
            }
            for(int i=0;i<sumba;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(t==6){
            cout<<6;
            if(sumling==1){
                cout<<0;
            }
            for(int i=0;i<sumba;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
    }
    return 0;
}
