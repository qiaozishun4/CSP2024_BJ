#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=20005;

int n;
int a[N];
ll f[2][N];

int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin>>T;
	while (T--) {
		memset(f,0,sizeof f);
		cin>>n;
		for (int i=1; i<=n; i++) cin>>a[i];
		for (int i=1; i<=n; i++) {
			memset(f[i&1^1],0,i*8+32);
			for (int j=0; j<i; j++) {
				f[i&1^1][j+1]=max(f[i&1^1][j+1],f[i&1][j]+a[i+1]*(a[i]==a[i+1]));
				f[i&1^1][0]=max(f[i&1^1][0],f[i&1][j]+a[i+1]*(a[i+1]==a[i-j-1]));
			}
		} ll maxn=0;
	 	for (int i=0; i<n; i++) maxn=max(maxn,f[n&1][i]);
		cout<<maxn<<'\n';
	}
	return 0;
}