#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<string,ll>mp;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		string s;
		cin>>s;
		mp[s]++;
	}
	cout<<52-(ll)(mp.size());
	return 0;
}