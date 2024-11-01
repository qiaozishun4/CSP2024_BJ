#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t[10]={6,2,5,5,4,5,6,3,7,6};
ll a[100005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		if(n<=1){
			cout<<"-1\n";
			continue;
		}
		ll x=0;
		while(1){
			x++;
			ll tmp=x,m=0;
			while(tmp>0){
				a[++m]=tmp%10;
				tmp/=10;
			}
			ll sum=0;
			for(ll i=1;i<=m;i++){
				sum+=t[a[i]];
			}
			if(sum==n){
				cout<<x<<"\n";
				break;
			}
		}
	}
	return 0;
}