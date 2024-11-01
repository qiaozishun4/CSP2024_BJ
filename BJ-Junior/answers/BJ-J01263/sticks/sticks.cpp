#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        int k=(c)/7;
        int t=c%7;
        if(c==0){
            for(int j=0;j<k;j++){
                cout<<8;
            }
        }
        if(c==1){
            if(k==0){cout<<-1<<"\n";continue;}
            cout<<10;
            for(int j=1;j<k;j++){
                cout<<8;
            }
        }
        if(c==2){

            cout<<1;
            for(int j=0;j<k;j++){
                cout<<8;
            }
        }
        if(c==3){
            if(k==0){cout<<7<<"\n";continue;}
            cout<<22;
            for(int j=1;j<k;j++){
                cout<<8;
            }
        }
        if(c==4){
            if(k==0){cout<<4<<"\n";continue;}
            cout<<20;
            for(int j=1;j<k;j++){
                cout<<8;
            }
        }
        if(c==5){
            cout<<2;
            for(int j=0;j<k;j++){
                cout<<8;
            }
        }
        if(c==6){
            cout<<6;
            for(int j=0;j<k;j++){
                cout<<8;
            }
        }
        cout<<endl<<c<<' '<<k<<' '<<t<<"\n";
    }
    return 0;
}
