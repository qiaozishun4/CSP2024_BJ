#include <bits/stdc++.h>
using namespace std;

struct Node {int x,id;}b[200005];
int T,n,a[200005],l[200005],cur;
long long f[200005],ans;
bool cmp(Node x,Node y) {return x.x != y.x ? x.x < y.x : x.id < y.id;}

int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		ans = cur = 0;
		for (int i = 1;i <= n;i++) {
			cin >> a[i];
			if (a[i] == a[cur]) ans += a[i];
			else a[++cur] = a[i];
		}
		n = cur;
		l[n + 1] = 0;
		a[n + 1] = 0;
		for (int i = 1;i <= n;i++) b[i] = Node{a[i],i};
		sort(b + 1,b + n + 1,cmp);
		for (int i = 1;i <= n;i++)
			if (b[i].x == b[i - 1].x) l[b[i].id] = b[i - 1].id;
			else l[b[i].id] = 0;
		f[0] = -1e18;
		for (int i = 2;i <= n;i++) {
			f[i] = max(f[i - 1],f[l[i]] + a[i]);
			if (a[i - 1] == a[i + 1]) f[i] += a[i - 1];
			else f[i] = max(f[i],f[l[i + 1]] + a[i + 1]);
		}
		cout << f[n] + ans << endl;
	}
	return 0;
}