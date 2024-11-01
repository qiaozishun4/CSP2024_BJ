#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5+10;
int n,vis[MAXN],a[MAXN],ans = 0;
void dfs(int x) {
	if(x==n+1) {
	//	for(int i = 1;i<=n;i++)
	//		cout<<vis[i]<<' ';
	//	cout<<endl;
		int sum = 0;
		for(int i = 1;i<=n;i++) 
			for(int j = i-1;j>=1;j--)
				if(vis[j]==vis[i]) {
//					cout<<"yes"<<endl;
					//cout<<i<<' '<<j<<endl;
					if(a[i]==a[j]) {
						sum += a[i];
						//cout<<"yes"<<endl;
					}
					break;
				}
	//	cout<<sum<<endl;
		ans = max(ans,sum);
		return;
	}
	vis[x] = 1;
	dfs(x+1);
	vis[x] = 0;
	dfs(x+1);
}
signed main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;cin>>T;
	while(T--) {
		ans = 0;
		cin>>n;
		for(int i = 1;i<=n;i++)
			cin>>a[i];
		dfs(1);
		cout<<ans<<endl;
	}
        return 0;
} 