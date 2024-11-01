#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7;

ll n,a[N],sum,T,t,wz,b[N];
bool vis[N],color[N];

void dfs(ll x,ll s,ll h,ll l){
	if(x==wz+1){
		sum=max(sum,s);
		return;
	}
	if(a[l]==b[x])
		dfs(x+1,s+b[l],h,x);
	else
		dfs(x+1,s,h,x);
	if(a[h]==a[x])
		dfs(x+1,s+b[x],x,l);
	else
		dfs(x+1,s,x,l);
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		memset(color,0,sizeof(color));
		memset(vis,0,sizeof(vis));
		memset(b,0,sizeof(b));
		sum=0;
		a[0]=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			color[a[i]]=1;
		}
		wz=1;
		for(int i=1;i<=n;i++){
			if(color[a[i+1]]==1||color[a[i]]==1){
				b[wz]=a[i];
				wz++;
			}
		}
		dfs(2,0,1,0);
		printf("%lld\n",sum);
	}
	return 0;
}
