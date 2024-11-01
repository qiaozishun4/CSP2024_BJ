#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int HC[]={6,2,5,5,4,5,6,3,7,6};
ll swfl(ll n){
    if(!n) return 6;
    ll x=0;
    while(n){
        x+=HC[n%10];
        n/=10;
    }
    return x;
}
ll hc(ll n){
    for(int i=1;;i++){
        if(swfl(i)==n) return i;
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ll t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        if(x==1) cout<<"-1\n";
        else {
            if(x%7==0){
                for(int i=1;i<=x/7;i++) cout<<"8";
                cout<<"\n";
            }else if(x%7==1){
                cout<<"10";
                x=x-8;
                for(int i=1;i<=x/7;i++) cout<<"8";
                cout<<"\n";
            }else cout<<hc(x)<<"\n";
        }
    }
    return 0;
}
