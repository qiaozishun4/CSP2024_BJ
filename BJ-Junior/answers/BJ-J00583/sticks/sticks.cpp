#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int k=n/7;
        if(n%7==0){for(int i=1;i<=k;i++)cout<<8;cout<<endl;}
        if(n%7==1){
            if(n==1){cout<<-1<<endl;}
            else{
                cout<<1<<0;
                for(int i=1;i<=k-1;i++)cout<<8;
                cout<<endl;
            }
        }
        if(n%7==2){
            cout<<1;
            for(int i=1;i<=k;i++)cout<<8;
            cout<<endl;
        }
        if(n%7==3){
            if(n==3){cout<<7<<endl;}
            else {if(n==10){cout<<22<<endl;}
                else{
                    cout<<2<<0<<0;
                    for(int i=1;i<=k-2;i++)cout<<8;
                    cout<<endl;
                }
            }
        }
        if(n%7==4){
            if(n==4){cout<<4<<endl;}
            else{
                cout<<2<<0;
                for(int i=1;i<=k-1;i++)cout<<8;
                cout<<endl;
            }
        }
        if(n%7==5){
            cout<<2;
            for(int i=1;i<=k;i++)cout<<8;
            cout<<endl;
        }
        if(n%7==6){
            cout<<6;
            for(int i=1;i<=k;i++)cout<<8;
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}