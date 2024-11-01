#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
int main(){
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	int n, m;
	int a[MAXN], c[MAXN];
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++) scanf("%d", &c[i]);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int x0, x1, x2, x3;
		scanf("%d%d%d%d", &x0, &x1, &x2, &x3);
		cout << x0 + x1 + x2 + x3 << endl;
	}
	return 0;
}
