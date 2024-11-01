#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e5+5;
ll n,a[MAXN];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll ans=n,val=0,r=1;
	for(int i=1;i<=n;++i){
		while(a[r]<a[i]){
			r++;
			val++;
		}
		if(val){
			ans--;
			val--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
