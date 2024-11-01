#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1){
            cout<<-1<<endl;continue;
        }else if(n==2){
            cout<<1<<endl;continue;
        }else if(n==3){
            cout<<7<<endl;continue;
        }else if(n==4){
            cout<<4<<endl;continue;
        }else if(n==5){
            cout<<2<<endl;
            continue;
        }else if(n==6){
            cout<<6<<endl;continue;
        }else if(n==9){
            cout<<24;continue;
        }else if(n==10){
            cout<<22;continue;
        }if(n%7==0){
            int v=n/7,num=0;
            for(int i=1;i<=v;i++)num*=10,num+=8;
            cout<<num<<endl;continue;
        }else if(n%7==1){
            int v=(n-8)/7,num=10;
            for(int i=1;i<=v;i++)num*=10,num+=8;
            cout<<num<<endl;continue;
        }else if(n%7==2){
            int v=(n-16)/7,num=220;
            for(int i=1;i<=v;i++)num*=10,num+=8;
            cout<<num<<endl;continue;
        }else if(n%7==3){
            int v=(n-17)/7,num=200;
            for(int i=1;i<=v;i++)num*=10,num+=8;
            cout<<num<<endl;continue;
        }else if(n%7==4){
            int v=(n-11)/7,num=20;
            for(int i=1;i<=v;i++)num*=10,num+=8;
            cout<<num<<endl;continue;
        }else if(n%7==5){
            int v=(n-12)/7,num=28;
            for(int i=1;i<=v;i++)num*=10,num+=8;
            cout<<num<<endl;continue;
        }else if(n%7==6){
            int v=(n-13)/7,num=80;
            for(int i=1;i<=v;i++)num*=10,num+=8;
            cout<<num<<endl;continue;
        }
    }
    return 0;
}
