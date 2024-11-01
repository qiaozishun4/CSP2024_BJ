#include<bits/stdc++.h>
using namespace std;
//int dp[100005];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int n,ans=0;
        cin>>n;
        if(n<2){cout<<-1<<endl;continue;}
        if(n==2){cout<<1<<endl;continue;}
        if(n==5){cout<<2<<endl;continue;}
        if(n==4){cout<<4<<endl;continue;}
        if(n==6){cout<<6<<endl;continue;}
        if(n==3){cout<<7<<endl;continue;}
        if(n%7==0){
            for(int i=1;i<=n/7;i++) ans=ans*10+8;
            cout<<ans<<endl;
            continue;
        }
        if(n%7==1){
            ans=10;
            for(int i=1;i<=n/7-1;i++) ans=ans*10+8;
            cout<<ans<<endl;
            continue;
        }
        if(n%7==2){
            ans=17;
            for(int i=1;i<=n/7-1;i++) ans=ans*10+8;
            cout<<ans<<endl;
            continue;
        }
        if(n%7==3){
            ans=22;
            for(int i=1;i<=n/7-1;i++) ans=ans*10+8;
            cout<<ans<<endl;
            continue;
        }
        if(n%7==4){
            ans=20;
            for(int i=1;i<=n/7-1;i++) ans=ans*10+8;
            cout<<ans<<endl;
            continue;
        }
        if(n%7==5){
            ans=28;
            for(int i=1;i<=n/7-1;i++) ans=ans*10+8;
            cout<<ans<<endl;
            continue;
        }
        if(n%7==6){
            ans=68;
            for(int i=1;i<=n/7;i++) ans=ans*10+8;
            cout<<ans<<endl;
            continue;
        }
    }
    return 0;
}
/*
0 6
1 2
2 5
4 4
6 6
7 3
8 7


13
68
*/