#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n%7==0){
            if(n==0) cout<<-1;
            else{
                int a=n/7;
                for(int j=1;j<=a;j++){
                    cout<<8;
                }
            }
        }
        else if(n%7==1){
            if(n==1){
                cout<<-1;
            }
            else{
                int a=(n-1)/7;
                cout<<10;
                for(int j=1;j<a;j++){
                    cout<<8;
                }
            }

        }
        else if(n%7==2){
            int a=(n-2)/7;
            cout<<1;
            for(int j=1;j<=a;j++){
                cout<<8;
            }
        }
        else if(n%7==3){
            if(n==3) cout<<7;
            else{
                int a=(n-3)/7;
                cout<<40;
                for(int j=1;j<a;j++){
                    cout<<8;
                }
            }

        }
        else if(n%7==4){
            if(n==4) cout<<4;
            else{
                int a=(n-4)/7;
                cout<<20;
                for(int j=1;j<a;j++){
                    cout<<8;
                }
            }
        }
        else if(n%7==5){
            int a=(n-5)/7;
            cout<<2;
            for(int j=1;j<=a;j++){
                cout<<8;
            }
        }
        else if(n%7==6){
            int a=(n-6)/7;
            cout<<6;
            for(int j=1;j<=a;j++){
                cout<<8;
            }
        }
        cout<<endl;
    }
    return 0;
}

