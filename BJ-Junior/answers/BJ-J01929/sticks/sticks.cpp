#include<bits/stdc++.h>
using namespace std;
//              0,1,2,3,4,5,6,7,8,9
int number[10]={6,2,5,5,4,5,6,3,7,6};
int hand[51]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,1088888,1888888,2008888,2088888,2888888,6888888,8888888,10888888};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    //hand[50]=10888888
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n>=50){
            int k=n%7,p=n/7;
            if(k==1){
                cout<<10;
                for(int i=1;i<p;i++)   cout<<8;
            }
            if(k==2){
                cout<<1;
                for(int i=1;i<=p;i++)   cout<<8;
            }
            if(k==3){
                cout<<200;
                for(int i=1;i<p-1;i++)   cout<<8;
            }
            if(k==4){
                cout<<20;
                for(int i=1;i<p;i++)   cout<<8;
            }
            if(k==5){
                cout<<2;
                for(int i=1;i<=p;i++)   cout<<8;
            }
            if(k==6){
                cout<<6;
                for(int i=1;i<=p;i++)   cout<<8;
            }
            if(k==0){
                cout<<8;
                for(int i=1;i<=p;i++)   cout<<8;
            }
        }else{
            cout<<hand[n];
        }
        cout<<'\n';
    }

    return 0;
}
