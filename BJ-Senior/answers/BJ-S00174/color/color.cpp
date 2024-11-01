#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int T,n,a[2010],f[2010][2010],dp[2010][2010];
vector<int> v[2010];
int work1(int x,int y) {
	int g=upper_bound(v[a[x]].begin(),v[a[x]].end(),min(x-2,y-1))-v[a[x]].begin();
	if (g==0) return 0;
	g--;
	int xx=v[a[x]][g];
	return dp[xx][y-1]+a[x];
}
int work2(int x,int y) {
	int g=upper_bound(v[a[y]].begin(),v[a[y]].end(),min(x-1,y-2))-v[a[y]].begin();
	if (g==0) return 0;
	g--;
	int yy=v[a[y]][g];
	return dp[x-1][yy]+a[y];
}
signed main(void) {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for (;T--;) {
		cin >> n;
		for (int i=1;i<=n;i++) cin >> a[i];
		for (int i=0;i<=n;i++)
			for (int j=0;j<=n;j++) f[i][j]=dp[i][j]=0;
		for (int i=1;i<=2000;i++) v[i].clear();
		for (int i=1;i<=n;i++) v[a[i]].push_back(i);
		for (int i=0;i<=n;i++) {
			for (int j=0;j<=n;j++) {
				if (i==j) {continue;}
				dp[i][j]=max(max((i>0)?(f[i-1][j]):0ll,(j>0)?f[i][j-1]:0ll),max(work1(i,j),work2(i,j)));
				f[i][j]=max(dp[i][j],max(((i>0)?f[i-1][j]:0ll),((j>0)?f[i][j-1]:0ll)));
			}
		}
		int ans=0;
		for (int i=0;i<=n;i++) ans=max(ans,max(dp[i][n],dp[n][i]));
		cout << ans << endl;
	}
	return 0;
}
