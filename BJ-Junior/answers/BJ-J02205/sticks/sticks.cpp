#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,a;
    long long b,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        if(n==1)cout<<-1<<"\n";
        else if(n==2)cout<<1<<"\n";
        else if(n==3)cout<<7<<"\n";
        else if(n==4)cout<<4<<"\n";
        else if(n==5)cout<<2<<"\n";
        else if(n==6)cout<<6<<"\n";
        else if(n==7)cout<<8<<"\n";
        
        else if(n==8)cout<<10<<"\n";
        else if(n==9)cout<<18<<"\n";
        else if(n==10)cout<<22<<"\n";
        else if(n==11)cout<<26<<"\n";
        else if(n==12)cout<<28<<"\n";
        else if(n==13)cout<<68<<"\n";
        else if(n==14)cout<<88<<"\n";
        
        else if(n==15)cout<<108<<"\n";
        else if(n==16)cout<<188<<"\n";
        else if(n==17)cout<<200<<"\n";
        else if(n==18)cout<<208<<"\n";
        else if(n==19)cout<<288<<"\n";
        else if(n==20)cout<<688<<"\n";
        else if(n==21)cout<<888<<"\n";
        else{
            a=n%7;
            b=n/7;
            if(a==0)for(int j=0;j<b;j++)cout<<8;
            else if(a==1){
                cout<<10;
                for(int j=0;j<b-1;j++)cout<<8;
            }
            else if(a==2){
                cout<<1;
                for(int j=0;j<b;j++)cout<<8;
            }
            else if(a==3){
                cout<<200;
                for(int j=0;j<b-2;j++)cout<<8;
            }
            else if(a==4){
                cout<<20;
                for(int j=0;j<b-1;j++)cout<<8;
            }
            else if(a==5){
                cout<<2;
                for(int j=0;j<b;j++)cout<<8;
            }
            else if(a==6){
                cout<<6;
                for(int j=0;j<b;j++)cout<<8;
            cout<<"\n";
            }
        }
    }
    return 0;
}