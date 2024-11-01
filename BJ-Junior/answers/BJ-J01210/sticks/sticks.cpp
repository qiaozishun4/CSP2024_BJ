#include<bits/stdc++.h>
using namespace std;
int a[50]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,608,688,888};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n<=21){
            cout<<a[n]<<endl;
        }else if(n%7==1){
            int x=n/7-1;
            cout<<2;
            for(int i=1;i<=x;i++){
                cout<<0;
            }
            cout<<2;
        }else if(n%7==2){
            int x=n/7;
            cout<<2;
            for(int i=1;i<=x;i++){
                cout<<0;
            }
        }else if(n%7==3){
            int x=n/7-1;
            cout<<2;
            for(int i=1;i<=x;i++){
                cout<<0;
            }
            cout<<8;
        }else if(n%7==4){
            int x=n/7-1;
            cout<<20;
            for(int i=1;i<=x;i++){
                cout<<8;
            }
        }else if(n%7==5){
            int x=n/7;
            cout<<2;
            for(int i=1;i<=x;i++){
                cout<<8;
            }
        }else if(n%7==6){
            int x=n/7;
            cout<<6;
            for(int i=1;i<=x;i++){
                cout<<8;
            }
        }else{
            int x=n/7;
            for(int i=1;i<=x;i++){
                cout<<8;
            }
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
