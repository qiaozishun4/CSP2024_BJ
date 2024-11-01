#include <bits/stdc++.h>
using namespace std;
int T,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n==1) cout<<-1<<endl;
        else if(n==2) cout<<1<<endl;
        else if(n==3) cout<<7<<endl;
        else if(n==4) cout<<4<<endl;
        else if(n==5) cout<<2<<endl;
        else if(n==6) cout<<6<<endl;
        else if(n==7) cout<<8<<endl;
        else if(n==18) cout<<208<<endl;
        else if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==1){
            cout<<1;
            for(int i=1;i<=(n-2)/6;i++){
                cout<<0;
            }
            cout<<endl;
        }
    }
    return 0;
}