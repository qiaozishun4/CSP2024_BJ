#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll solve(ll x){
    ll f=x/7,t=x;
    t-=f*7;
    ll ans=0;
    if(f==0){
        if(t==2){
            ans=1;
        }else if(t==3){
            ans=7;
        }else if(t==4){
            ans=4;
        }else if(t==5){
            ans=2;
        }else{
            ans=6;
        }
        return ans;
    }
    if(t==0){
        for(int i=1;i<=f;i++)ans=ans*10+8;
    }else if(t==1){
        ans=10;
        for(int i=1;i<f;i++)ans=ans*10+8;
    }else if(t==2){
        ans=1;
        for(int i=1;i<=f;i++)ans=ans*10+8;
    }else if(t==3){
        ans=22;
        for(int i=1;i<f;i++)ans=ans*10+8;
    }else if(t==4){
        ans=20;
        for(int i=1;i<f;i++)ans=ans*10+8;
    }else if(t==5){
        ans=2;
        for(int i=1;i<=f;i++)ans=ans*10+8;
    }else{
        ans=68;
        for(int i=1;i<f;i++)ans=ans*10+8;
    }
    return ans;
}
int main(){
    freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        ll x;
        scanf("%lld",&x);
        if(x==1){
            printf("-1\n");
            continue;
        }
        printf("%lld\n",solve(x));
    }
    return 0;
}
