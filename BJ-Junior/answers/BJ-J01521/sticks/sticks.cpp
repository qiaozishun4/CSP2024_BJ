#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x,t[50];
void set_up(){
    t[0]=-1;
    t[1]=-1;
    t[2]=1;
    t[3]=7;
    t[4]=4;
    t[5]=3;
    t[6]=6;
    t[7]=8;
    t[8]=10;
    t[9]=24;
    t[10]=25;
    t[11]=20;
    t[12]=28;
    t[13]=68;
    t[14]=88;
    t[15]=108;
    t[16]=188;
    t[17]=200;
    t[18]=208;
    t[19]=288;
    t[20]=688;
}
signed main(){
    set_up();
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int j=0;j<n;j++){
        cin>>x;
        if(x<=20){
            cout<<t[x]<<"\n";
            continue;
        }
        if(x%7==0)for(int i=0;i<x/7;i++)cout<<8;
        if(x%7==1){
            x-=36;
            for(int i=0;i<x/7;i++)cout<<8;
            for(int i=0;i<6;i++)cout<<0;
        }
        cout<<'\n';
    }
    return 0;
}