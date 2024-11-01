#include<bits/stdc++.h>
using namespace std;
int T;
int biao[40]={-1,-1,1,7,4,2,6,8,10,18,23,20,28,60,88,108,188,228,208,288,688,888,1088};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n<=20){
            cout<<biao[n]<<"\n";
        }
        else if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<"\n";
        }
        else if(n%7==1){
            cout<<10;
            for(int i=1;i<=(n-8)/7;i++){
                cout<<8;
            }
            cout<<"\n";
        }
        else if(n%7==2){
            cout<<1;
            for(int i=1;i<=(n-2)/7;i++){
                cout<<8;
            }
            cout<<"\n";
        }
        else if(n%7==3){
            cout<<22;
            for(int i=1;i<=(n-10)/7;i++){
                cout<<8;
            }
            cout<<"\n";
        }
        else if(n%7==4){
            cout<<20;
            for(int i=1;i<=(n-11)/7;i++){
                cout<<8;
            }
            cout<<"\n";
        }
        else if(n%7==5){
            cout<<2;
            for(int i=1;i<=(n-2)/7;i++){
                cout<<8;
            }
            cout<<"\n";
        }
        else if(n%7==6){
            cout<<6;
            for(int i=1;i<=(n-6)/7;i++){
                cout<<8;
            }
            cout<<"\n";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}