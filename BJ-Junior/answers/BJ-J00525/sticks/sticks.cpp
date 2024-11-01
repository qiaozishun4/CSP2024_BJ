#include<bits/stdc++.h>
using namespace std;

int t,n;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    cin>>t;
    while(t--){
        cin>>n;

        if(n==1){cout<<"-1\n";continue;}

        int x=n/7;
        int y=n%7;

        if(y==1){x--;cout<<10;}
        if(y==2){cout<<1;}
        if(y==3){x--;cout<<22;}
        if(y==4){x--;cout<<20;}
        if(y==5){cout<<2;}
        if(y==6){cout<<6;}

        for(int i=1;i<=x;i++)
            cout<<8;

        cout<<"\n";
    }

    return 0;
}
