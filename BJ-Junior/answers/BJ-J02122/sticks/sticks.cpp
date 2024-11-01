#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=7){
            switch(n){
                case 2:cout<<1<<endl;break;
                case 3:cout<<7<<endl;break;
                case 4:cout<<4<<endl;break;
                case 5:cout<<2<<endl;break;
                case 6:cout<<6<<endl;break;
                case 7:cout<<8<<endl;break;
                default:cout<<-1<<endl;break;
            }
            continue;
        }
        switch(n%7){
            case 0:
                for(int i=1;i<=n/7;i++)cout<<8;
                break;
            case 1:
                cout<<1<<0;
                for(int i=2;i<=n/7;i++)cout<<8;
                break;
            case 2:
                cout<<1;
                for(int i=1;i<=n/7;i++)cout<<8;
                break;
            case 3:
                cout<<2<<2;
                for(int i=2;i<=n/7;i++)cout<<8;
                break;
            case 4:
                cout<<2<<0;
                for(int i=2;i<=n/7;i++)cout<<8;
                break;
            case 5:
                cout<<2;
                for(int i=1;i<=n/7;i++)cout<<8;
                break;
            case 6:
                cout<<6;
                for(int i=1;i<=n/7;i++)cout<<8;
            default:break;
        }
        cout<<endl;
    }
    return 0;
}
