#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[200005];
bool col[200005];
map<ll,ll> mp;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(),cout.tie();
	cin>>t;
	while(t--){
		ll ans=0;
		cin>>n;
		for(ll i=1;i<=n;i++) cin>>a[i];
		if(n<=20){
			for(ll i=1;i<(1<<n);i++){
				ll x=0;
				for(ll j=0;j<n;j++){
					col[j+1]=((i>>j)&1);
				}
				for(ll j=1;j<=n;j++){
					for(ll k=j-1;k>=1;k--){
						if(col[k]==col[j]){
							if(a[j]==a[k]) x+=a[j];
							break;
						}
					}
				}
				ans=max(ans,x);
			}
			cout<<ans<<"\n";
		}else{
			mp.clear();
			for(ll i=1;i<=n;i++){
				mp[a[i]]++;
			}
			for(auto i:mp){
				ans+=i.first*(i.second-1);
			}cout<<ans<<"\n";
		}
	}
	return 0;
}
