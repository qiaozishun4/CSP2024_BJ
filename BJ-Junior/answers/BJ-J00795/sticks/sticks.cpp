#include<bits/stdc++.h>
using namespace std;

int T,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n;
        if(n==1)cout<<-1;
        else if(n==2)cout<<1;
        else if(n==3)cout<<7;
        else if(n==4)cout<<4;
        else if(n==5)cout<<2;
        else if(n==6)cout<<6;
        else if(n==7)cout<<8;
        else if(n==8)cout<<10;
        else if(n==9)cout<<18;
        else if(n==10)cout<<22;
        else if(n==11)cout<<26;
        else if(n==12)cout<<28;
        else if(n==13)cout<<68;
        else if(n==14)cout<<88;
        else if(n==15)cout<<108;
        else if(n==16)cout<<188;
        else if(n==17)cout<<206;
        else if(n==18)cout<<208;
        else if(n==19)cout<<288;
        else if(n==20)cout<<688;
        else if(n%7==0){
            for(int j=1;j<=n/7;j++)cout<<8;
        }
        else if(n%7==1){
            cout<<10;
            for(int j=1;j<=n/7-1;j++)cout<<8;
        }
        else if(n%7==2){
            cout<<1;
            for(int j=1;j<=n/7;j++)cout<<8;
        }
        else if(n%7==3){
            cout<<7;
            for(int j=1;j<=n/7;j++)cout<<8;
        }
        else if(n%7==4){
            cout<<4;
            for(int j=1;j<=n/7;j++)cout<<8;
        }
        else if(n%7==5){
            cout<<2;
            for(int j=1;j<=n/7;j++)cout<<8;
        }
        else if(n%7==6){
            cout<<6;
            for(int j=1;j<=n/7;j++)cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
