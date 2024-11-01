#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,bool> mp;
ll ans=52,n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		string temp;
		cin>>temp;
		if(mp[temp]==0){
			ans--;
			mp[temp]=1;
		}
	}
	printf("%lld",ans);
	return 0;
}
