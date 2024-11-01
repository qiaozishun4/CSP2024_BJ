#include<bits/stdc++.h>
using namespace std;
//int a[10]={6,2,5,5,4,5,6,3,7,6};

int main(){
    int t;
    freopen("sticks1.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        else if(n%7==1){
            cout<<16;
            n-=8;
        }
        else if(n%7==2){
            cout<<1;
            n-=2;
        }
        else if(n%7==3){
            cout<<7;
            n-=3;
        }
        else if(n%7==4){
            cout<<4;
            n-=4;
        }
        else if(n%7==5){
            cout<<2;
            n-=5;
        }
        else if(n%7==6){
            cout<<6;
            n-=6;
        }
        while(n>0){
            n-=7;
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
