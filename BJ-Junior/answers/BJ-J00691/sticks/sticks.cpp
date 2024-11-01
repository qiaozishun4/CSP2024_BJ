#include<bits/stdc++.h>
using namespace std;
int cnt[]={6,2,5,5,4,5,6,3,7,6};
int T,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n==1){
            cout<<-1<<'\n';
            continue;
        }if(n==4){
            cout<<4<<'\n';
            continue;
        }if(n==3){
            cout<<7<<'\n';
            continue;
        }
        int yu=n%7;
        if(yu==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
        }else if(yu==1){
            cout<<10;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
        }else if(yu==2){
            cout<<1;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
        }else if(yu==3){
            cout<<40;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
        }else if(yu==4){
            cout<<20;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
        }else if(yu==5){
            cout<<2;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
        }else if(yu==6){
            cout<<6;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
        }cout<<'\n';
    }
    return 0;
}
