#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int r=1;r<=t;r++){
            cin>>n;
        if(n==1)
            cout<<-1;
        else if(n==2)
            cout<<1;
        else if(n==3)
            cout<<7;
        else if(n==4)
            cout<<4;
        else if(n==5)
            cout<<2;
        else if(n==6)
            cout<<6;
        else{
            if(n%7==0){
                cout<<8;
                for(int i=1;i<=(n-7)/7;i++)
                    cout<<8;
            }else if(n%7==1){
                cout<<10;
                for(int i=1;i<=(n-8)/7;i++)
                    cout<<8;
            }else if(n%7==2){
                cout<<18;
                for(int i=1;i<=(n-9)/7;i++)
                    cout<<8;
            }else if(n%7==3){
                cout<<22;
                for(int i=1;i<=(n-10)/7;i++)
                    cout<<8;
            }else if(n%7==4){
                cout<<20;
                for(int i=1;i<=(n-11)/7;i++)
                    cout<<8;
            }else if(n%7==5){
                cout<<28;
                for(int i=1;i<=(n-12)/7;i++)
                    cout<<8;
            }else if(n%7==6){
                cout<<68;
                for(int i=1;i<=(n-13)/7;i++)
                    cout<<8;
            }
        }
        cout<<endl;
    }
    return 0;
}