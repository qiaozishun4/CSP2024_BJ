#include<iostream>
#include<stdio.h>
using namespace std;
int t;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        if(n<=1)
            cout<<-1<<endl;
        else if(n%7==0){
            for(int j=0;j<n/7;j++)
                cout<<8;
            cout<<endl;
        } else if(n%7==1){
            cout<<10;
            n-=8;
            for(int j=0;j<n/7;j++)
                cout<<8;
            cout<<endl;
        } else if(n%7==2){
            cout<<1;
            n-=2;
            for(int j=0;j<n/7;j++)
                cout<<8;
            cout<<endl;
        } else if(n%7==3){
            if(n<10)
                cout<<7<<endl;
            else{
                cout<<40;
                n-=10;
                for(int j=0;j<n/7;j++)
                    cout<<8;
                cout<<endl;
            }
        } else if(n%7==4){
            if(n<11)
                cout<<4<<endl;
            else{
                cout<<20;
                n-=11;
                for(int j=0;j<n/7;j++)
                    cout<<8;
                cout<<endl;
            }
        } else if(n==5){
            cout<<2;
            n-=5;
            for(int j=0;j<n/7;j++)
                cout<<8;
            cout<<endl;
        } else if(n==6){
            cout<<6;
            n-=6;
            for(int j=0;j<n/7;j++)
                cout<<8;
            cout<<endl;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}