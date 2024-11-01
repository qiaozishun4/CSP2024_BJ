#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+105;
ll a[N],b[N],cnt;
stack <ll> sta;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        b[a[i]]++;
    }
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--){
        sta.push(b[a[i]]);
    }
    while(sta.size()!=1){
        int n=sta.top();
        sta.pop();
        int m=sta.top();
        sta.pop();
        if(n>=m) sta.push(n);
        else sta.push(m);
    }
    ll ans=sta.top();
    cout<<ans;
    return 0;
}