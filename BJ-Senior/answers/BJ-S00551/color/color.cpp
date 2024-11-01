#include <bits/stdc++.h>
using namespace std;
const int maxn=2*1e4+7;
int vis[maxn],a[maxn],c[maxn],ans=0;
void solve(int n){
	memset(c,0,sizeof(c));
	c[1]=0;
	for(int i=2;i<=n;i++)
		for(int j=i-1;j>=1;j--)
			if(vis[i]==vis[j]){
				if(a[i]==a[j])
					c[i]=a[i];
				break;
			}
		

	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=c[i];
	}
	ans=max(ans,sum);
}
void dfs(int x,int n){
	if(x==n+1){
		
		solve(n);
		return;
	}
	vis[x]=1;
	dfs(x+1,n);
	vis[x]=0; 
	dfs(x+1,n);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t; cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c)); ans=0;
		int n; cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		dfs(1,n);
		cout<<ans<<endl;
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
