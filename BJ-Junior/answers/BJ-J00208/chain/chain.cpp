#include <iostream>
#include <cstdio>
using namespace std;
int T,n,k,q;
bool can[200010];
int g[200010],v[2010][2010],t[2010];
bool is=0;
int a,b;
void dfs(int x,int stp,int p=0) {
	if (x==a&&stp==b) {
		is=1;
		return;
	}
	if (stp>b) return;
	for (int i=1;i<=n;i++) {
		if (i==p) continue;
		for (int j=1;j<=t[i];j++)
			if (v[i][j]==x)
				for (int kk=j+1;kk<=min(j+k-1,t[i]);kk++) {
					dfs(v[i][kk],stp+1,i);
					if (is==1) return;
				}
	}
}
int main(void) {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for (;T--;) {
		for (int i=1;i<=200000;i++) can[i]=0;
		cin >> n >> k >> q;
		for (int i=1;i<=n;i++) {
			int l;
			cin >> l;
			t[i]=l;
			for (int j=1;j<=l;j++) cin >> g[j],v[i][j]=g[j];
			for (int j=1;j<=l;j++)
				if (g[j]==1)
					for (int kk=j+1;kk<=min(j+k-1,l);kk++)
						can[g[kk]]=1;
		}
		for (int t1,t2;q--;) {
			cin >> t1 >> t2;
			if (t1==1)
				cout << can[t2] << endl;
			else {
				is=0;
				a=t2,b=t1;
				dfs(1,0);
				cout << is << endl;
			}
		}
	}
	return 0;
}