#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int ci;cin>>ci;
    while(ci--){
        int n,eight=0;cin>>n;
        eight=max(((n-8)/7),0);
        n-=(eight*7);
        if(n==1){cout<<-1;}
        else if(n==2){cout<<1;}
        else if(n==3){cout<<7;}
        else if(n==4){cout<<4;}
        else if(n==6){cout<<5;}
        else if(n==7){cout<<8;}
        else if(n==8){cout<<10;}
        else if(n==9){cout<<18;}
        else if(n==10){cout<<22;}
        else if(n==11){cout<<20;}
        else if(n==12){cout<<28;}
        else if(n==13){cout<<68;}
        else if(n==14){cout<<88;}
        for(int i=1;i<=eight;i++){
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
