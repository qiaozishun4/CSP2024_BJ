#include<bits/stdc++.h>
using namespace std;
int t,n,a[200100],ans;
void dfs(int x,int s,int tr,int tb) {
	if(x-1==n) {
		ans=max(ans,s);
		return;
	}
	if(a[x]==tr) {
		dfs(x+1,s+tr,a[x],tb);
	}
	else {
		dfs(x+1,s,a[x],tb);
	}
	if(a[x]==tb) {
		dfs(x+1,s+tb,tr,a[x]);
	}
	else {
		dfs(x+1,s,tr,a[x]);
	}
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--) {
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		dfs(1,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}