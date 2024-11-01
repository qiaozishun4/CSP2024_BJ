#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[200005];
ll val10(ll x,ll y){
    if(x==y){
        return 0;
    }
    if(a[x]==a[y]){
        return a[x];
    }
    else{
        return 0;
    }
}
//ll cnt=0;
ll dfs(ll x,ll l0,ll l1){
//    cnt++;
    if(x==n){
//        cout<<x<<" "<<val10(x,l0)<<" "<<val10(x,l1)<<endl;
        return max(val10(x,l0),val10(x,l1));
    }
    ll sum1=dfs(x+1,x,l1)+val10(x,l0);
    ll sum2=dfs(x+1,l0,x)+val10(x,l1);
//    if(x==1){
//        cout<<"QwQ "<<val10(x,l0)<<" "<<val10(x,l1)<<endl;
//    }
//    cout<<x<<" "<<sum1<<" "<<sum2<<endl;
    return max(sum1,sum2);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        a[0]=0;
        cout<<max(dfs(1,0,1),dfs(1,1,0))<<endl;
    }
    return 0;
}
