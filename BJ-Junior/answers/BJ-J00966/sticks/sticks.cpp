#include<bits/stdc++.h>
using namespace std;
int n,x;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>x;
        if(x==7) cout<<8;
        else if(x==6) cout<<6;
        else if(x==5) cout<<2;
        else if(x==4) cout<<4;
        else if(x==3) cout<<7;
        else if(x==2) cout<<1;
        else if(x==1) cout<<-1;
        else{
            if(x%7==0) cout<<88;
            if(x%7==1) cout<<10;
            if(x%7==2) cout<<18;
            if(x%7==3) cout<<22;
            if(x%7==4) cout<<20;
            if(x%7==5) cout<<28;
            if(x%7==6) cout<<68;
            for(int i=1;i<x/7;i++) cout<<8;
        }cout<<endl;
    }
    return 0;
}
