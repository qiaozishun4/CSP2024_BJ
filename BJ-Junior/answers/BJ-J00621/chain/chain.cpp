#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,k,q,l[200005],s,r,c;
bool h[200005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(),cout.tie();
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(ll i=1;i<=n;i++){
			cin>>l[i];
			for(ll j=1;j<=l[i];j++){
				cin>>s;h[s]=1;
			}
		}
		while(q--){
			cin>>r>>c;
			cout<<h[c]<<"\n";
		}
	}
	return 0;//zpyzpy
}
