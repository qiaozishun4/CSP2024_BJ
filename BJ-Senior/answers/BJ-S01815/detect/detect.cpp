#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e5+10;
int d[MAXN],v[MAXN],a[MAXN],p[MAXN];
signed main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;cin>>T;
	while(T--) {
		int n,m,l,V;cin>>n>>m>>l>>V;
		for(int i = 1;i<=n;i++) 
			cin>>d[i]>>v[i]>>a[i];
		for(int i = 1;i<=m;i++)
			cin>>p[i];
		sort(p+1,p+m+1);
		int ans = 0;
		for(int i = 1;i<=n;i++)
			if(d[i]<=p[m]&&v[i]>V)
				ans++;
		cout<<ans<<' ';
		if(ans!=0)	cout<<m-1<<endl;
		else		cout<<m<<endl;
	}
        return 0;
} 
