#include<iostream>
using namespace std;
#define N 100005
int b[N]={}, nxt[N];

signed main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	cin >> n;
	for (int i=1;i<=n;i++) {
		int r;
		cin >> r;
		b[r]++;
	}
	for (int i=0;i<N-1;i++) {
		nxt[i] = i+1;
	}
	int ans=0;
	for (int i=nxt[0],pre=0;i;i=nxt[i]) {
		if (!b[i]) nxt[pre] = nxt[i];
		else pre=i;
	}
	while(nxt[0]) {
		for (int i=nxt[0],pre=0;i;i=nxt[i]) {
			// cout << i << "->"; //
			if (b[i]) b[i]--;
			if (!b[i]) nxt[pre] = nxt[i];
			else pre=i;
		}
		// cout << endl; //
		ans++;
	}
	cout << ans;
	return 0;
}
