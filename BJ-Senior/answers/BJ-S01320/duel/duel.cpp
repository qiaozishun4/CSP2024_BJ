#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll a[100010];
ll type;
vector<ll>v;
ll sum[100010];
ll use[100010];
ll ans;
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(sum[a[i]]==0){
			type++;
			v.push_back(a[i]);
		}
		sum[a[i]]++;
		use[a[i]]++;
	}
	sort(v.begin(),v.end());
	//cout<<num[0]<<","<<num[1];
	if(type==2){
		sum[v[0]]-=sum[v[1]];
		if(sum[v[0]]<0)
		sum[v[0]]=0;
		cout<<sum[v[0]]+sum[v[1]];
	}else if(type==1){
		cout<<sum[v[0]];
	}else{
		for(ll i=0;i<v.size();i++){
			ll r=v[i];
			for(ll j=i+1;j<v.size()&&sum[r];j++){
				if(use[v[j]]>=sum[r]){
					use[v[j]]-=sum[r];
					sum[r]=0;
				}else{
					sum[r]-=use[v[j]];
					use[v[j]]=0;
				}
			}
			ans+=sum[r];
		}
		cout<<ans;
	}
	return 0;
}
