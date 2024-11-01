#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ll n,m,p[100005],L,V,d[100005],v[100005],a[100005],ans=0;
		scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
		}for(ll i=1;i<=m;i++){
			scanf("%lld",&p[i]);
		}for(ll i=1;i<=n;i++){
			if(v[i]>V&&d[i]<=p[m]){
				ans++;
			}
		}
		printf("%lld ",ans);
		if(ans){
			printf("%lld\n",m-1);
		}else{
			printf("%lld\n",m);
		}
	}
	return 0;
}