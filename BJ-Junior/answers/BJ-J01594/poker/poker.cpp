#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
string s;
map<string,ll>mp;
ll cnt;
signed main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>s;
		if(mp[s]==0)
		cnt++;
		mp[s]++;
	}
	cout<<52-cnt;
	return 0;
}
