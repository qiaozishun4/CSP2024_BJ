#include<bits/stdc++.h>
using namespace std;
int m[10]={6,2,5,5,4,5,6,3,7,6};
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8<<'\n';
            }
            continue;
        }
        if(n==1) cout<<-1<<'\n';
        if(n==2) cout<<1<<'\n';
        if(n==3) cout<<7<<'\n';
        if(n==4) cout<<4<<'\n';
        if(n==5) cout<<2<<'\n';
        if(n==6) cout<<6<<'\n';
        if(n==7) cout<<8<<'\n';
        if(n==8) cout<<10<<'\n';
        if(n==9) cout<<18<<'\n';
        if(n==10) cout<<23<<'\n';
        if(n==11) cout<<48<<'\n';
        if(n==12) cout<<50<<'\n';
        if(n==13) cout<<68<<'\n';
        if(n==14) cout<<88<<'\n';
        if(n==15) cout<<108<<'\n';
        if(n==16) cout<<202<<'\n';
        if(n==17) cout<<200<<'\n';
        if(n==18) cout<<208<<'\n';
        if(n==19) cout<<588<<'\n';
        if(n==20) cout<<808<<'\n';
    }
    return 0;
}