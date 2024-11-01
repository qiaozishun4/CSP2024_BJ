#include <iostream>
using namespace std;
int T,n;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n==2){
            cout<<1<<endl;
        }
        if(n==3){
            cout<<7<<endl;
        }
        if(n==4){
            cout<<4<<endl;
        }
        if(n==5){
            cout<<5<<endl;
        }
        if(n==6){
            cout<<6<<endl;
        }
        if(n%7==0){
            for(int j=1;j<=n/7;j++){
                cout<<8;
            }
            cout<<endl;
        }
        if(n%7==1){
                cout<<10;
            for(int j=1;j<=(n-8)/7;j++){
                cout<<8;
            }
            cout<<endl;
        }
    }
    return 0;
}
