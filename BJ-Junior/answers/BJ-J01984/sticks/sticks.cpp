#include<bits/stdc++.h>
using namespace std;
void solve(int n){
        if(n==1)cout<<-1;
        if(n==2)cout<<1;
        if(n==3)cout<<7;
        if(n==4)cout<<4;
        if(n==5)cout<<2;
        if(n==6)cout<<6;
        if(n==8)cout<<10;
        if(n==9)cout<<18;
        if(n==10)cout<<22;
        if(n==11)cout<<20;
        if(n==12)cout<<28;
        if(n==13)cout<<67;
        if(n==15)cout<<167;
        if(n==16)cout<<188;
        if(n==17)cout<<228;
        if(n==18)cout<<208;
        if(n==19)cout<<288;
        if(n==20)cout<<688;
        if(n%7==0){
            for(int i=1;i<=(n/7);i++){
                cout<<8;
            }
        }
        cout<<"\n";
        return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,i=0;
    cin>>T;
    while(T--){
        int s;
        cin>>s;
        solve(s);
    }
    return 0;
}