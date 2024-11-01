#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,x;
    cin>>T;
    while(T--){
        cin>>x;
        if(x%7==1){
            if(x==1){
                cout<<-1<<"\n";
                continue;
            }
            cout<<"10";
            x=x-8;
        }
        if(x%7==2){
            cout<<"1";
            x=x-2;
        }
        if(x%7==3){
            if(x==3){
                cout<<7<<"\n";
                continue;
            }
            if(x==10){
                cout<<22<<"\n";
                continue;
            }
            cout<<"200";
            x=x-17;
        }
        if(x%7==4){
            if(x==4){
                cout<<4<<"\n";
                continue;
            }
            cout<<"20";
            x=x-11;
        }
        if(x%7==5){
            cout<<"2";
            x=x-5;
        }
        if(x%7==6){
            cout<<"6";
            x=x-6;
        }
        for(int i=x;i>=1;i-=7){
            cout<<"8";
        }
        cout<<"\n";
    }
    return 0;
}