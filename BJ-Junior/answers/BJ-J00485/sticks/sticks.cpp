#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n;
void get(int a){
    int q=a/7,r=a%7;
    if(a==1){
        cout<<-1;
    }else if(r==0){
        while(q--)cout<<8;
    }else if(r==1){
        cout<<10;
        while(--q)cout<<8;
    }else if(r==2){
        cout<<1;
        while(q--)cout<<8;
    }else if(r==3&&q>=1){
        cout<<22;
        while(--q)cout<<8;
    }else if(r==3&&q==0){
        cout<<7;
    }else if(r==4&&q==0){
        cout<<4;
    }else if(r==4&&q>=1){
        cout<<20;
        while(--q)cout<<8;
    }else if(r==5){
        cout<<2;
        while(q--)cout<<8;
    }else if(r==6){
        cout<<6;
        while(q--)cout<<8;
    }else{
        cout<<-1;
    }
    cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        get(n);
    }
    return 0;
}
