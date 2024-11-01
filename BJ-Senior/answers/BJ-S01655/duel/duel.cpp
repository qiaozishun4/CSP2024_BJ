#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n;
ll mp[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ll mx=0;
	for(ll i=1;i<=n;i++){
		ll e;
		cin>>e;
		mp[e]++;
		mx=max(mx,e);
	}
	ll r=0,pre=0;
	for(ll i=1;i<=mx;i++){
		if(mp[i]==0) continue;
		if(pre==0){
			pre=i;
			continue;
		}
		if(mp[i]<=mp[pre]){
			r+=mp[pre]-mp[i];
		}
		else{
			ll x=mp[i]-mp[pre];
			if(x-r>=0) r=0;
			else r-=x;
		}
		pre=i;
	}
	cout<<r+mp[mx];
	return 0;
}
