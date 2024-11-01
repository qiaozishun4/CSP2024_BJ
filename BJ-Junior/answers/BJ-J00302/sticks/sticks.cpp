#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,t;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while (t--){
        cin>>n;
        if (n==1) cout<<-1;
        else if (n==6) cout<<6;
        else if (n==4) cout<<4;
        else if (n%7==0) for (ll i=1;i<=n/7;i++) cout<<8;
        else if (n%7==1){
            cout<<16;
            for (ll i=1;i<n/7;i++) cout<<8;
        }
        else if (n%7==2){
            cout<<1;
            for (ll i=1;i<=n/7;i++) cout<<8;
        }
        else if (n%7==3){
            cout<<7;
            for (ll i=1;i<=n/7;i++) cout<<8;
        }
        else if (n%7==4){
            cout<<20;
            for (ll i=1;i<n/7;i++) cout<<8;
        }
        else if (n%7==5){
            cout<<5;
            for (ll i=1;i<=n/7;i++) cout<<8;
        }
        else if (n%7==6){
            cout<<6;
            for (ll i=1;i<=n/7;i++) cout<<8;
        }
        cout<<'\n';
    }
    return 0;
}
