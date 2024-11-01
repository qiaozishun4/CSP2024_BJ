#include<bits/stdc++.h>
using namespace std;

int n;
int a[100010];

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	
	sort(a + 1, a + n + 1);
	int cnt = 0;
	for(int i = 1, j; i <= n; i = j){
		j = i;
		while(j <= n && a[j] == a[i]) j++;
		
		int len = j - i;
		cnt -= len;
		if(cnt < 0) cnt = 0;
		cnt += len;
	}
	
	printf("%d\n", cnt);
	return 0;
}