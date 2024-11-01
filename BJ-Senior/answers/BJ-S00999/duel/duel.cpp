#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ptr=1,ans;
ll a[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    ans=n;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=2;i<=n;i++)
        if(a[ptr]<a[i]){
            ans--;
            ptr++;
        }
    cout<<ans<<'\n';
    return 0;
}