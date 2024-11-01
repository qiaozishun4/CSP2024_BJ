#include<bits/stdc++.h>
#define MAXN 20
using namespace std;

int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, a[MAXN];
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		printf("%d\n", a[1]);
	}
	return 0;
}
