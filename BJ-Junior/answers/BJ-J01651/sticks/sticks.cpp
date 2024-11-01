#include<iostream>
#include<cstdio>
#define For(v,s,e) for(int v=s;v<=e;v++)
using namespace std;
int T;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    For(te,1,T){
        int n;
        cin>>n;
        if(n<=7){
            switch(n){
                case 1:cout<<-1;break;
                case 2:cout<<1;break;
                case 3:cout<<7;break;
                case 4:cout<<4;break;
                case 5:cout<<2;break;
                case 6:cout<<6;break;
                case 0:cout<<8;break;
            }
        }
        else if(n%7==0){
            For(i,1,n/7)cout<<8;
        }else if(n%7==1){
            cout<<"10";
            For(i,1,(n-1)/7-1)cout<<8;
        }else if(n%7==2){
            cout<<"1";
            For(i,1,(n-2)/7)cout<<8;
        }else if(n%7==3){
            cout<<"22";
            For(i,1,(n-3)/7-1)cout<<8;
        }else if(n%7==4){
            cout<<"20";
            For(i,1,(n-4)/7-1)cout<<8;
        }else if(n%7==5){
            cout<<"2";
            For(i,1,(n-5)/7)cout<<8;
        }else if(n%7==6){
            cout<<"6";
            For(i,1,(n-6)/7)cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
