#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,m,l,V;
ll d[N],v[N],a[N],p[N];
int main(){
	freopen("detect.in.in","r",stdin);
	freopen("detect.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		cin>>n>>m>>l>>V;
		for(ll i=1;i<=n;i++){ 
			cin>>d[i]>>v[i]>>a[i];
		}
		for(ll i=1;i<=m;i++) cin>>p[i];
		ll ans1=0;
		for(ll i=1;i<=n;i++){
			if(v[i]>V) ans1++;
		}
		cout<<ans1<<" "<<n-1;
	}
	return 0;
}
