#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n;
ll a[15]={6,2,5,4,6,3,7};
ll b[15]={0,1,2,4,6,7,8};
ll ans=0x3f3f3f3f3f3f3f3fLL;
void dfs(ll now,ll num){
    // cout<<now<<" "<<num<<'\n';
    if(num>n)
        return;
    if(num==n){
        ans=min(ans,now);
        return;
    }
    if(now>ans)
        return;
    for(ll i=0;i<7;i++){
        if(now==0&&num==0&&i==0)
            continue;
        if(num+a[i]>n)
            continue;
        dfs(now*10+b[i],num+a[i]);
    }
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0x3f3f3f3f3f3f3f3fLL;
        if(n>=100){
            if(n%7==0)
                for(ll i=1;i<=n/7;i++)
                    cout<<8;
            else{
                cout<<10;
                for(ll i=1;i<=(n-8)/7;i++)
                    cout<<8;
            }
            cout<<'\n';
            continue;
        }
        dfs(0,0);
        cout<<(ans==0x3f3f3f3f3f3f3f3fLL?-1:ans)<<'\n';
    }
    return 0;
}