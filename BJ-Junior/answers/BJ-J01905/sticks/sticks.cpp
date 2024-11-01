#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1)cout<<"-1";
        else if(n==3)cout<<"7";
        else if(n==4)cout<<"4";
        else if(n%7==0){
            for(int i=1;i<=n/7;i++)cout<<'8';
        }else if(n%7==1){
            cout<<"10";n-=8;
            for(int i=1;i<=n/7;i++)cout<<'8';
        }else if(n%7==2){
            cout<<"1";n-=2;
            for(int i=1;i<=n/7;i++)cout<<'8';
        }else if(n%7==3){
            cout<<"23";n-=11;
            for(int i=1;i<=n/7;i++)cout<<'8';
        }else if(n%7==4){
            cout<<"20";n-=11;
            for(int i=1;i<=n/7;i++)cout<<'8';
        }else if(n%7==5){
            cout<<"2";n-=5;
            for(int i=1;i<=n/7;i++)cout<<'8';
        }else if(n%7==6){
            cout<<"6";n-=6;
            for(int i=1;i<=n/7;i++)cout<<'8';
        }
        cout<<'\n';
    }
    return 0;
}