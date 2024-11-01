#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n==3){
            cout<<7<<endl;
            continue;
        }
        if(n==10){
            cout<<22<<endl;
            continue;
        }
        if(n==4){
            cout<<4<<endl;
            continue;
        }
        int p=n/7;
        if(n%7!=0){
            p++;
        }
        int q=n%7;
        if(q==2){
            cout<<1;
            p--;
            for(int i=1;i<=p;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(q==3){
            cout<<200;
            p-=3;
            for(int i=1;i<=p;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(q==4){
            cout<<20;
            p-=2;
            for(int i=1;i<=p;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(q==5){
            cout<<3;
            p--;
            for(int i=1;i<=p;i++){
                cout<<8;
            }
        }
        else if(q==6){
            cout<<6;
            p--;
            for(int i=1;i<=p;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(q==0){
            for(int i=1;i<=p;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else{
            cout<<10;
            p-=2;
            for(int i=1;i<=p;i++){
                cout<<8;
            }
            cout<<endl;
        }
    }
    return 0;
}
