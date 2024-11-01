#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int s,m,t,n;cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n==1){
            cout<<"-1"<<endl;
            continue;
        }
        if(n%7==0){
            for(int j=0;j<n/7;j++)cout<<'8';
            cout<<endl;
            continue;
        }
        if(n%7==1){
            cout<<"10";
            for(int j=0;j<n/7-1;j++)cout<<'8';
            cout<<endl;
            continue;
        }
        if(n%7==2){
            cout<<"1";
            for(int j=0;j<n/7;j++)cout<<'8';
            cout<<endl;
            continue;
        }
        if(n%7==3){
            if(n==3){
                cout<<"7";
                cout<<endl;
                continue;
            }
            if(n==10){
                cout<<"22";
                cout<<endl;
                continue;
            }
            cout<<"200";
            for(int j=0;j<n/7-2;j++)cout<<'8';
            cout<<endl;
            continue;
        }
        if(n%7==4){
            if(n==4){
                cout<<'4'<<endl;
                continue;
            }
            cout<<"20";
            for(int j=0;j<n/7-1;j++)cout<<'8';
            cout<<endl;
            continue;
        }
        if(n%7==5){
            cout<<"2";
            for(int j=0;j<n/7;j++)cout<<'8';
            cout<<endl;
            continue;
        }
        if(n%7==6){
            cout<<"6";
            for(int j=0;j<n/7;j++)cout<<'8';
            cout<<endl;
            continue;
        }
    }
    return 0;
}