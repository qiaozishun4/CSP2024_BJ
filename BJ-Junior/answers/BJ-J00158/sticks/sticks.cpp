#include<iostream>
 using namespace std;
 int a[5][20];
 void solve(){
     int n;
     cin>>n;
     int a,b;
     a=n/7,b=(7-(n%7))%7;
     if(b==1) cout<<6;
     if(b==2) cout<<2;
     if(b==3){
        if(a>=1) cout<<20;
        else cout<<4;
        a--;
     }
     if(b==4){
        if(a>=2) cout<<200;
        else if(a==1) cout<<22;
        else cout<<7;
        a-=2;
     }
     if(b==5) cout<<1;
     if(b==6){
        if(a>=1) cout<<10;
        else cout<<-1;
        a--;
     }
     for(int i=1;i<=a;i++) cout<<8;
     cout<<endl;
 }
 int main(){
     freopen("sticks.in","r",stdin);
     freopen("sticks.out","w",stdout);
     int T;
     cin>>T;
     while(T--) solve();
     return 0;
 }
