#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define pll pair<ll,ll>
#define mkp make_pair
using namespace std;
inline ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x*f;
}
ll a[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ll n=read();
    priority_queue<ll,vector<ll>,greater<ll> > q;
    rep(i,1,n){
        a[i]=read();
        q.push(a[i]);
    }
    sort(a+1,a+n+1);
    rep(i,1,n){
        if(a[i]<=q.top()){
            continue;
        }
        q.pop();
    }
    printf("%lld\n",q.size());
    return 0;
}
