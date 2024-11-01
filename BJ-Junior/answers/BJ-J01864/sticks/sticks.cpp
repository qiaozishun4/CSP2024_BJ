#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
int T,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    rep(i,T){
        cin>>n;
        if(n<=1)cout<<-1;
        else if(n%7==0){
            int x=n/7;
            rep(j,x)cout<<8;
        }else if(n%7==1){
            cout <<10;
            n-=8;
            int x=n/7;
            rep(j,x)cout<<8;
        }else if(n>7){
            int x=n/7-1;
            int y=n%7+7;
            if(y==9) cout<<18;
            else if(y==10)cout<<22;
            else if(y==11)cout<<20;
            else if(y==12)cout<<28;
            else if(y==13)cout<<68;
            rep(j,x)cout<<8;
        }else if(n<7&&n>1){
            if(n==2)cout<< 1;
            else if(n==3)cout<<7;
            else if(n==4)cout<<4;
            else if(n==5)cout<<3;
            else if(n==6)cout<<6;
        }
        cout<<endl;
    }

    return 0;
}
