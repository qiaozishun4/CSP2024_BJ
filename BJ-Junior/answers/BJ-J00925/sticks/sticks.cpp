#include<iostream>
using namespace std;
int t;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        else if(n==2){
            cout<<1<<endl;
            continue;
        }
        else if(n==3){
            cout<<7<<endl;
            continue;
        }
        else if(n==4){
            cout<<4<<endl;
            continue;
        }
        else if(n==5){
            cout<<2<<endl;
            continue;
        }
        else if(n==6){
            cout<<6<<endl;
            continue;
        }
        else if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        else if(n%7==1){
            cout<<16;
            for(int i=1;i<=(n-8)/7;i++){
                cout<<8;
            }
            cout<<endl;
        }
    }
    return 0;
}
