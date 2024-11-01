#include<bits/stdc++.h>
using namespace std;
void solve(){
    int x;cin>>x;
    if(x==1){cout<<-1<<"\n";return ;}
    if(x<=7){
        if(x==2)cout<<1;
        if(x==3)cout<<7;
        if(x==4)cout<<4;
        if(x==5)cout<<2;
        if(x==6)cout<<6;
        if(x==7)cout<<8;
        cout<<"\n";return ;
    }
    int n=x%7;
    if(n==1)cout<<10;
    if(n==2)cout<<18;
    if(n==3)cout<<22;
    if(n==4)cout<<20;
    if(n==5)cout<<28;
    if(n==6)cout<<68;
    if(n==0)cout<<8;
    int cnt=x-n;
    cnt/=7;cnt-=1;
    for(int i=1;i<=cnt;i++)cout<<8;
    cout<<"\n";
}
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
