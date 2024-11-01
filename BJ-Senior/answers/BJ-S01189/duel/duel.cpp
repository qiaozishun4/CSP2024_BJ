#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n, r[MAXN];
	scanf("%d", &n);
	int a[MAXN], c = 0, cnt[MAXN];
	memset(a, 0, sizeof(a));
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++) scanf("%d", &r[i]);
	sort(r + 1, r + n + 1);
	for(int i = 1; i <= n; i++)
	{
		if(a[c] != r[i]) 
		{
			a[++c] = r[i];
			cnt[c]++;
		}
		else cnt[c]++;
	}
	sort(cnt + 1, cnt + n + 1, cmp);
	printf("%d\n", cnt[1]);
	return 0;
	
}
