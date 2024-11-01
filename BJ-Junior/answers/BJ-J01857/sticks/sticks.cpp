#include<iostream>
#include<cstdio>
#include<iomanip>


using namespace std;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        if(n<=1){
            cout<<"-1"<<endl;
            continue;
        }
        if(n==2){
            cout<<'1'<<endl;
            continue;
        }
        if(n==3){
            cout<<'7'<<endl;
            continue;
        }
        if(n==4){
            cout<<"4"<<endl;
            continue;
        }
        if(n==5){
            cout<<"2"<<endl;
            continue;
        }
        if(n==6){
            cout<<"6"<<endl;
            continue;
        }
        int a=n/7;
        if(n%7==0){
            for(int j=1;j<=a;j++){
                cout<<'8';
            }
        }
        else if(n%7==1){
            cout<<"12";
            a--;
            for(int j=1;j<=a;j++){
                cout<<'8';
            }
        }
        cout<<endl;
    }
    return 0;
}