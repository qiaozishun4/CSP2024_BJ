#include<bits/stdc++.h>
using namespace std;

int a[200010];
int n;

bool bj[200010];

long long ans = 0;
void dfs(int step){
	if(step == n + 1){
		long long sum = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i - 1; j >= 1; j--){
				if(bj[i] == bj[j]){
					if(a[i] == a[j]) sum += a[j];
					break;
				}
			}
		}
		ans = max(ans, sum);
		return ;
	}
	
	bj[step] = true;
	dfs(step + 1);
	bj[step] = false;
	dfs(step + 1);
}

int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", a + i);
		
		dfs(1);
		printf("%lld\n", ans);
		ans = 0;
	}
	return 0;
}