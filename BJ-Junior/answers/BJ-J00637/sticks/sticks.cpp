#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;

        if(n==2)cout<<1<<endl;
        if(n==1||n==0)cout<<-1<<endl;
        if(n==6)cout<<6<<endl;
        if(n==3)cout<<7<<endl;
        if(n==4)cout<<4<<endl;
        if(n==5)cout<<2<<endl;
        if(n==7)cout<<8<<endl;
        if(n<=7)continue;
        if(n%7==6){
            n-=6;
            cout<<6;
        }
        if(n%7==5){
            n-=5;
            cout<<2;
        }
        if(n%7==4){
            n-=11;
            cout<<20;
            if(n==0)cout<<endl;
        }
        if(n%7==3){
            n-=3;
            cout<<7;
        }
        if(n%7==2){
            n-=2;
            cout<<1;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }
        if(n%7==1){
            int m=n/7;
            cout<<10;
            for(int i=1;i<=m-1;i++){
                cout<<8;
            }
            cout<<endl;
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
