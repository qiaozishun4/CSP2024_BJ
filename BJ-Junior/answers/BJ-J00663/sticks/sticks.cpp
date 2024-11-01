#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n<7){
            if(n==1)cout<<-1<<endl;
            else if(n==2)cout<<1<<endl;
            else if(n==3)cout<<7<<endl;
            else if(n==4)cout<<4<<endl;
            else if(n==5)cout<<2<<endl;
            else if(n==6)cout<<6<<endl;
        }
        else if(n%7==0){
            for(int j=1;j<=n/7;j++){
                cout<<8;
            }
            cout<<endl;
        }
        else if((n-1)%7==0){
            cout<<10;
            for(int o=1;o<(n-1)/7;o++)cout<<8;
            cout<<endl;
        }

         else if((n-2)%7==0){
                cout<<1;
                for(int p=1;p<=(n-2)/7;p++)cout<<8;
                cout<<endl;
             }
             else if((n-3)%7==0){
                cout<<22;
                for(int w=1;w<(n-3)/7;w++)cout<<8;
                cout<<endl;
             }
             else if((n-4)%7==0){
                cout<<20;
                for(int y=1;y<(n-4)/7;y++)cout<<8;
                cout<<endl;
             }
             else if((n-5)%7==0){
                cout<<28;
                for(int h=1;h<(n-5)/7;h++)cout<<8;
                cout<<endl;
             }
             else if((n-6)%7==0){
                cout<<68;
                for(int b=1;b<(n-6)/7;b++)cout<<8;
                cout<<endl;
             }

            }
    }


