#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,a[200005],c[200005],color[200005],vis[200005][5],ans;

void init(){
	ans=0;
	for(ll i=1;i<=n;i++){
		color[i]=0;
		c[i]=0;
		vis[i][1]=vis[i][2]=0;
	}
}

ll f(){
	ll sum=0;
	for(ll i=1;i<=n;i++){
		for(ll j=i-1;j>=1;j--){
			if(color[j]==color[i]){
				if(a[j]==a[i]){
					c[i]=a[i];
				}
			}
		}
	}
	for(ll i=1;i<=n;i++){
		sum+=c[i];
	}
	return sum;
}
void dfs(ll x){
	if(x>n) {
		ans=max(ans,f());
		return ;
	}
	for(ll i=1;i<=2;i++){
		if(vis[x][i]==0){
			color[x]=i;
			dfs(x+1);
			vis[x][i]=0;
		}	
	}
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);	
	
	cin>>T;
	while(T--){
		init();
		cin>>n;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		dfs(1);
		printf("%lld\n",ans);
	}	
	return 0;
}
